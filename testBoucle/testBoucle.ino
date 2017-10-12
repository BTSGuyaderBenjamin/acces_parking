#include "arduino.h"
#include <Wire.h>
#include "I2C.h"

void setup() {

  Serial.begin(9600);
  Wire.begin();
  initI2C(122);
  
}

void loop() {
  int variable;
  int valeur;
  Wire.requestFrom(0x20, 1);  
  while(Wire.available()){
    variable = Wire.read();    
    Serial.print((variable & 0x20)>>5);
  }
  valeur = (variable & 0x20)>>5;
  delay(1000);
  if(valeur==0){
    Wire.beginTransmission(0x20);             //Bit de start + adresse
    Wire.write(0xFD);                         //Trame
    Wire.endTransmission();                   //Bit de stop
    delay(30000);
  }
  Wire.beginTransmission(0x20);             //Bit de start + adresse
  Wire.write(0xFE);                         //Trame
  Wire.endTransmission();                   //Bit de stop
  delay(1000);
}

