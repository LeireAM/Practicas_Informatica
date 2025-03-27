#include <stdint.h>

//definir pines para LEDs
uint8_t L1 = 18;
uint8_t P1 = 5;
uint8_t P2 = 21;

//Varaibles para temporizadores
uint64_t previous_millis_L1= 0;


//intervalos
uint64_t L1_interval = 10000;



void setup() {
  // configurar pines como salidas
  Serial.begin(9600);
  pinMode(L1, OUTPUT);
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);


  //inicializar leds apagadps
  digitalWrite(L1, LOW);


}

void loop() {
  uint64_t actual_millis = millis();
  if(digitalRead(P1) == false){
      delay(100);
      digitalWrite(L1, true);
    
    }else if(actual_millis - previous_millis_L1 > L1_interval || digitalRead(P2) == false){
    delay(100);
    previous_millis_L1 = millis();
    if(digitalRead(L1)){
       digitalWrite(L1, false);
  }
    }

}

  