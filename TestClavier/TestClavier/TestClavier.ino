#include "I2C.h"
#include <Wire.h>
#include <Keypad.h>

  const byte ROWS = 4;
  const byte COLS = 3;

  char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
  };


void setup(){
  Serial.begin(9600);
  Wire.begin();
}


void loop(){
  int variable;
  Wire.requestFrom(0x22, 1);  
  while(Wire.available()){
    variable = Wire.read();                  
    Serial.println(variable & 
  }
}
