#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int8_t sensorPin = 32;
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64


Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop() {
  // put your main code here, to run repeatedly:
  int32_t value = 0;
  value = digitalRead(sensorPin);
  display.clearDisplay();
  display.setTextSize(1);//tamaño
  display.setTextColor(SSD1306_WHITE);//color
  display.setCursor(10, 32);

  if(value == LOW){
    Serial.println("Obstaculo detectado");
    display.println("Obstaculo detectado");
    
  }else{
   
    Serial.println("Obstaculo NO detectado");
    display.println("Obstaculo NO detectado");

  }
  display.display();
  delay(1000);
}
