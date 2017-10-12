#include "arduino.h"
#include <Wire.h>
#include "I2C.h"



void setup() {
  Wire.begin();
  initI2C(122);  
}

void loop() {
  Wire.beginTransmission(0x20);             //Bit de start + adresse
  Wire.write(0xFD);                         //Trame
  Wire.endTransmission();                   //Bit de stop
  delay(1000);                              //Delais
  Wire.beginTransmission(0x20);             //Bit de start + adresse
  Wire.write(0xFE);                         //Trame
  Wire.endTransmission();                   //Bit de stop
  delay(1000);                              //Delais

}

