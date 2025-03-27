#include <stdint.h>

uint8_t red_led = 2;
uint8_t green_led = 5;

void setup() {
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void loop() {
  
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, LOW);
  delay(1000);


  digitalWrite(red_led, LOW);
  digitalWrite(green_led, HIGH);
  delay(1000);
}
