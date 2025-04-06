#include <stdint.h>

//definir pines para LEDs
uint8_t LR1 = 2; // rojo coches
uint8_t LA1 = 4; //amarillo coches
uint8_t LV1 = 5; //verde coches
uint8_t LR2 = 18; //rojo peaton
uint8_t LA2 = 21; //amarillo perosnas
uint8_t LV2 = 22; //verde personar
uint8_t P1 = 23; //boton para pasar personas


//Varaibles para temporizadores
uint64_t previous_millis = 0;
uint64_t button_pushed = false; //para manter el boton pulsado
int32_t situation = 0;// para el switch


//intervalos
uint64_t ambar_interval = 2000;
uint64_t green_people_interval = 20000;
uint64_t red_interval = 2000;




void setup() {
  // configurar pines como salidas
  Serial.begin(9600);
  pinMode(LR1, OUTPUT);
  pinMode(LA1, OUTPUT);
  pinMode(LV1, OUTPUT);
  pinMode(LR2, OUTPUT);
  pinMode(LA2, OUTPUT);
  pinMode(LV2, OUTPUT);
  pinMode(P1, INPUT_PULLUP);
  
  //inicializar leds apagadps
  digitalWrite(LR1, LOW);
  digitalWrite(LA1, LOW);
  digitalWrite(LV1, LOW);
  digitalWrite(LR2, LOW);
  digitalWrite(LA2, LOW);
  digitalWrite(LV2, LOW);
}

void loop() {
  
  if(digitalRead(P1) == false){
      delay(100);
      button_pushed = true;
   }
   while(button_pushed == true){//empieza el bucle para peatones
      uint64_t actual_millis = millis();

      switch(situation){
       case 0: // poner en ambar coches
       if(actual_millis - previous_millis >= ambar_interval) {
          previous_millis = actual_millis;
          digitalWrite(LR1, LOW);
          digitalWrite(LA1, HIGH);
          digitalWrite(LV1, LOW);
          digitalWrite(LR2, HIGH);
          digitalWrite(LA2, LOW);
          digitalWrite(LV2, LOW);
          situation = 1;
         }
       break;
       case 1: // poner en rojo coches
        if (actual_millis - previous_millis >= ambar_interval) {
          previous_millis = actual_millis;
          digitalWrite(LR1, HIGH);
          digitalWrite(LA1, LOW);
          digitalWrite(LV1, LOW);
          digitalWrite(LR2, HIGH);
          digitalWrite(LA2, LOW);
          digitalWrite(LV2, LOW);
          situation = 2;
        }
       break;
       case 2: // poner verde personas
        if (actual_millis - previous_millis >= red_interval) {
          previous_millis = actual_millis;
          digitalWrite(LR1, HIGH);
          digitalWrite(LA1, LOW);
          digitalWrite(LV1, LOW);
          digitalWrite(LR2, LOW);
          digitalWrite(LA2, LOW);
          digitalWrite(LV2, HIGH);
          situation = 3;
        }
       break;
       case 3: // poner en ambar personas
        if (actual_millis - previous_millis >= green_people_interval) {
          previous_millis = actual_millis;
          digitalWrite(LR1, HIGH);
          digitalWrite(LA1, LOW);
          digitalWrite(LV1, LOW);
          digitalWrite(LR2, LOW);
          digitalWrite(LA2, HIGH);
          digitalWrite(LV2, LOW);
          situation = 4;
        }
       break;
       case 4: // poner en rojo personas
        if (actual_millis - previous_millis >= ambar_interval) {
          previous_millis = actual_millis;
          digitalWrite(LR1, HIGH);
          digitalWrite(LA1, LOW);
          digitalWrite(LV1, LOW);
          digitalWrite(LR2, HIGH);
          digitalWrite(LA2, LOW);
          digitalWrite(LV2, LOW);
          situation = 5;
        }
       break;
       case 5: // poner en rojo personas
        if (actual_millis - previous_millis >= red_interval) {
          previous_millis = actual_millis;
          situation = 0;
          button_pushed = false;
        }
       break;
      }

     }   
      digitalWrite(LR1, LOW);
      digitalWrite(LA1, LOW);
      digitalWrite(LV1, HIGH);
      digitalWrite(LR2, HIGH);
      digitalWrite(LA2, LOW);
      digitalWrite(LV2, LOW);
  }
   

 
