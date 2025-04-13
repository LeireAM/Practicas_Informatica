#include <stdint.h> //para el print

// Pin del buzzer
#define buzzer 33

// Pin del sensor
int8_t PIRPin = 32;


void setup() {
  Serial.begin(115200);
  // Pin del PIR como entrada
  pinMode(PIRPin, INPUT);
}

void loop() {
  int32_t input = digitalRead(PIRPin);
  Serial.print("MOVIMIENTO: "); //Comprobar la entrada 
  Serial.println(input);

  if(input == true){ //si se activa la entrada que se active la salida
    tone(buzzer, 2000); //activar el buzzer
    delay(500);   
  } else { //si no se activa la entrada:
    noTone(buzzer); //desactivar el buzzer
  }
  delay(200); // Delay para evitar lecturas demasiado rápidas
}