#include "fonction.h"
#include "Arduino.h"
#include "affiche.h"
#include "I2C.h"
#include <Wire.h>


void setup() {
  Serial.begin(9600);
  Wire.begin();
  initI2C(122);

}

void loop() {
  int variable;
  Wire.requestFrom(0x22, 1);   
  while(Wire.available()){
    variable = Wire.read();
    Serial.print(variable);
  }
  delay(1000);

}

