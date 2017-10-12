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

