#include <EEPROM.h>
#include <SoftwareSerial.h>
SoftwareSerial mySUART(8,9);


const byte PWM = 4;

String frequency;

void setup() {
  // put your setup code here, to run once:
  pinMode(PWM, OUTPUT);
  EEPROM.get(0, frequency);
  EEPROM.put(0, frequency.toFloat());
  tone(PWM, frequency.toFloat());
  Serial.println(frequency.toFloat());
  Serial.begin(9600);
  mySUART.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySUART.available()){
    frequency = mySUART.readString();
    EEPROM.put(0, frequency.toFloat());
    tone(PWM, frequency.toFloat());
    Serial.println(frequency.toFloat());
  }
}
