#define potenciometro 22
int portValue = 0;
#define pinLed1 5
#define pinLed2 4
#define pinLed3 15
#define buzzer 21



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  portValue = analogRead(potenciometro);
  Serial.println(portValue);

  if(portValue >= 300){
    digitalWrite(pinLed1, HIGH);
    tone(buzzer, 25000);
  } else if(portValue < 1365){
    digitalWrite(pinLed1, LOW);
  }

 if(portValue >= 2730){
    digitalWrite(pinLed2, HIGH);
    tone(buzzer, 45000);
  }else if(portValue < 2730){
  digitalWrite(pinLed2, LOW);
 }

  if(portValue >= 4095){
    digitalWrite(pinLed3, HIGH);
    tone(buzzer, 55000);
  }else if(portValue < 4095){
    digitalWrite(pinLed3, LOW);
  }
}
