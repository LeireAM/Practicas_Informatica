#include <stdint.h>

//definir pines para LEDs
uint8_t red_led = 18;
uint8_t button = 5;

bool led_state = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(red_led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button) == LOW){
    delay(100);
    led_state =! led_state;
    digitalWrite(red_led, led_state);
  }
}
