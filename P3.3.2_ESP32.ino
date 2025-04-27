#include <WiFi.h>
#include "time.h"
#include <stdint.h>
#include <PubSubClient.h>

// WIFI
const char* ssid = "iPhone de Leire";
const char* password = "Leire1234";

// Servidor para fecha y hora
const char* ntpServer = "es.pool.ntp.org";

// Zona horaria
const int32_t gmtOffset_sec = 3600;

// Horario de verano
const int32_t daylightOffset_sec = 0;

// Estructura para trabajar con NTP
struct tm timeinfo;

// MQTT
const char* mqtt_username = "leire1";
const char* mqtt_password = "1357";
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient mqtt_client(espClient);

//LED
#define LED1 2

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el tópico: ");
  Serial.println(topic);

  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Mensaje: ");
  Serial.println(message);

  if (message == "1") {
    Serial.println("ON");
    digitalWrite(LED1, HIGH);
  } else if (message == "0") {
    Serial.println("OFF");
    digitalWrite(LED1, LOW);
  }
}

void reconnect() {
  while (!mqtt_client.connected()) {
    Serial.print("Conectando a MQTT...");
    String client_id = "esp32-client-" + String(WiFi.macAddress());
    
    if (mqtt_client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Conectado");
      mqtt_client.subscribe("sensor/boton");
    } else {
      Serial.print("Error, código: ");
      Serial.println(mqtt_client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Conexión wifi
  Serial.println("Conectando a Wifi...");
  WiFi.begin(ssid, password);

//comprobar que el tiempo de conexion es menor que 15s para ver si conecta el wifi
uint36_t conectingTime = millis();

while (WiFi.status() != WL_CONNECTED && millis() - conectingtTime < 15000) {
    Serial.print(".");
    delay(500);
}

if (WiFi.status() != WL_CONNECTED) {
    Serial.println("\nERROR: No se pudo conectar al WiFi.");
} else {
    Serial.println("\nConexión WiFi establecida.");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());
}
 

  // Fecha y hora
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  // Configurar MQTT
  mqtt_client.setServer(mqtt_server, mqtt_port);
  mqtt_client.setCallback(callback);

  //led
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
}

void loop() {
  if (!mqtt_client.connected()) {
    reconnect();
  }
  
  mqtt_client.loop(); // Procesa mensajes MQTT
  
  if (getLocalTime(&timeinfo)) {
    Serial.println(&timeinfo, "%d/%m/%Y %H:%M:%S");
    String currentTime = 
      String(timeinfo.tm_mday) + "/" + String(timeinfo.tm_mon + 1) + "/" + String(timeinfo.tm_year + 1900) + " " + String(timeinfo.tm_hour) + ":" +  String(timeinfo.tm_min) + ":" + String(timeinfo.tm_sec);
    
    mqtt_client.publish("sensor/hora", currentTime.c_str());
  } else {
    Serial.println("Error obteniendo la hora");
  }
 

  delay(1000);
}