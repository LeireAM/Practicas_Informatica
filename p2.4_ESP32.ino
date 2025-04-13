#include <DHT.h>
#include <stdint.h>

// Configuración del sensor
#define DHTPIN 23           // Pin donde está conectado el sensor
#define DHTTYPE DHT11      // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

// Pines para los LEDs
#define LED_VERDE 5
#define LED_AZUL 4
#define LED_ROJO 15

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Configurar pines de los LEDs
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
}

void loop() {
  delay(5000);
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  // Verificar que la lectura sea válida
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer del sensor DHT11");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C | Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  // Apagar todos los LEDs por defecto
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_ROJO, LOW);

  // Condiciones
 

  if (temperatura < 20) {
    digitalWrite(LED_VERDE, HIGH);
  }else{
    digitalWrite(LED_VERDE, LOW);
  }

  if (temperatura > 15) {
    digitalWrite(LED_AZUL, HIGH);
  }

  if (temperatura > 15 && temperatura < 20 && humedad < 20) {
    digitalWrite(LED_ROJO, HIGH);
  }

  delay(2000); // Espera entre lecturas
}