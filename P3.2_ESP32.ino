#include <WiFi.h>
#include "time.h"
#include <stdint.h>
#include <PubSubClient.h>

//WIFI
const char* ssid = "WIFI_MESH_1EA0";
const char* password = "fCY4dPSfzhh";

//servidor para fecha y hora
const char* ntpServer = "es.pool.ntp.org";
 
//zona horaria 
const int32_t gmtOffset_sec = 3600;

//horario de verano
const int32_t daylightOffset_sec = 0;

//Estructura para trabajar con ntp
struct tm timeinfo;

//MQTT
const char* mqtt_username = "leire1";
const char* mqtt_password = "1357";
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient mqtt_client(espClient);

void setup() {
  Serial.begin(115200);

  //conexion wifi
  Serial.println("Conectado a Wifi...");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
    Serial.println("\nConexión Wifi establecida.");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());
  
  //fecha y hora
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  //confugurar MQTT
  mqtt_client.setServer(mqtt_server, mqtt_port);

}

void loop() {

  mqtt_client.loop(); //procesa mensajes MQTT
  getLocalTime(&timeinfo);
  Serial.println(&timeinfo, "%d %m %Y %H:%M:%S");
  String currentTime = String(timeinfo.tm_mday) + "/" + String(timeinfo.tm_mon + 1) + "/" + String(timeinfo.tm_year + 1900) + "/" + String(timeinfo.tm_hour) + ":" +  String(timeinfo.tm_min) + ":" + String(timeinfo.tm_sec);
  if(mqtt_client.connected()){
    mqtt_client.publish("sensor/hora", currentTime.c_str());
  }
  delay(1000);
}
