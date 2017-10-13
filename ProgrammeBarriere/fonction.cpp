#include "fonction.h"
#include "Arduino.h"
#include "affiche.h"

#include <Wire.h>

int boucleAmont(){
  int variableAmont;
  Wire.requestFrom(0x20, 1);   
  while(Wire.available())    
  { 
    variableAmont = Wire.read();    
    variableAmont = (variableAmont & 0x20)>>5;    
  } 
  return variableAmont; 
}

int boucleAval(){
  int variableAval;
  Wire.requestFrom(0x20, 1);   
  while(Wire.available())    
  { 
    variableAval = Wire.read();    
    variableAval = (variableAval & 0x40)>>6;    
  } 
  return variableAval; 
}

int validation(){
  int variableValidation;
  Wire.requestFrom(0x21, 1);   
  while(Wire.available()){
    variableValidation = Wire.read();
    variableValidation = (variableValidation & 0x01);
  }
  return variableValidation;
}

void ouvrir(){
    Wire.beginTransmission(0x20);             //Bit de start + adresse
    Wire.write(0xFD);                         //Trame
    Wire.endTransmission();                  //Bit de stop
    delay(1000);
}

void fermer(){
    Wire.beginTransmission(0x20);             //Bit de start + adresse
    Wire.write(0xFE);                         //Trame
    Wire.endTransmission();                   //Bit de stop
    delay(1000);
}

