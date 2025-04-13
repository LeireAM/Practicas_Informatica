#include <stdint.h>

// Pines para el RGB
#define pinLedRojo 5
#define pinLedVerde 4
#define pinLedAzul 15

// Pin del LDR
int8_t LDRPin = 32;


void setup() {
  Serial.begin(9600);
  
  // Configuración de pines LED como salida
  pinMode(pinLedRojo, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedAzul, OUTPUT);

  // Pin del LDR como entrada
  pinMode(LDRPin, INPUT);
}

void loop() {
  int32_t input = digitalRead(LDRPin);
  Serial.print("Nivel de luz: ");//comprobar entrada
  Serial.println(input);

  if(input == true){ //si no se detecta luz:
    digitalWrite(pinLedRojo, HIGH);     // Rojo encendido
    digitalWrite(pinLedVerde, HIGH);    // Verde encendido
    digitalWrite(pinLedAzul,HIGH);   // Azul encendido

  } else { //si hay luz mantener los leds apagados
    digitalWrite(pinLedRojo, LOW);
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedAzul, LOW);
  }
  delay(200); //delay para evitar lecturas demasiado rápidas
}