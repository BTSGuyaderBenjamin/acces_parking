#include "Arduino.h"
#include "I2C.h"
#include <Wire.h>


void setup() {
  Serial.begin(9600);
  Wire.begin();
  initI2C(122);

}

void loop() {
  int variable;
  Wire.requestFrom(0x21, 1);   
  while(Wire.available()){
    variable = Wire.read();
    Serial.print("Detection Carte :  ");
    Serial.println(variable & 0x01);
  }
  delay(1000);

}

