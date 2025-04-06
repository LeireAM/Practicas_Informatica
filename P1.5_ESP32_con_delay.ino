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
uint64_t previous_millis_LR1= 0;
uint64_t previous_millis_LA1= 0;
uint64_t previous_millis_LV1= 0;
uint64_t previous_millis_LR2= 0;
uint64_t previous_millis_LA2= 0;
uint64_t previous_millis_LV2= 0;
uint64_t button_pushed = false; //para manter el boton pulsado



//intervalos
uint64_t LA1_interval = 5000;
uint64_t LR1_interval = 5000;
uint64_t LA2_interval = 44000;
uint64_t wait_interval = 37000;



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
  uint64_t actual_millis = millis();

  if(digitalRead(P1) == false){
      delay(100);
      button_pushed = true;
   }
   while(button_pushed == true){
      digitalWrite(LA1, true);
      digitalWrite(LV1, false);
      digitalWrite(LR2, true); 
      digitalWrite(LR1, false);
      digitalWrite(LV2, false);
      digitalWrite(LA2, false);
     
      delay(2000);
       digitalWrite(LA1, false);
        digitalWrite(LR1, true);
        digitalWrite(LR2, true);
        digitalWrite(LV1, false);
        digitalWrite(LV2, false);
        digitalWrite(LA2, false);
     
     delay(2000);
        digitalWrite(LR2, false);
        digitalWrite(LR1, true);
        digitalWrite(LV2, true); 
      
      delay(30000);
        digitalWrite(LV2, false);
        digitalWrite(LA2, true);
     
     delay(2000);
        digitalWrite(LR2, true);
        digitalWrite(LA2, false);

     delay(2000);
        digitalWrite(LV1, true);

        button_pushed = false;
        break;
     }
       
    digitalWrite(LV1, true);
    digitalWrite(LR2, true);
    digitalWrite(LR1, false);
    digitalWrite(LV2, false);
    digitalWrite(LA2, false);
    digitalWrite(LA1, false);
  }
   
