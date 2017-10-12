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
  int tempo = 0, testTempo;
  static int nombreVoiture = 0;
  
  if(boucleAmont()==0 && boucleAval()==1){
    testTempo=1;
    Wire.beginTransmission(0x20);             //Bit de start + adresse
    Wire.write(0xFD);                         //Trame
    Wire.endTransmission();                  //Bit de stop
    delay(1000);
    while(boucleAmont()==0 && boucleAval()==1 && testTempo==1){
      tempo++;
      delay(10);
      if(tempo == 1000){
        testTempo=0;
      }
    }
    if(boucleAmont()==1 || boucleAval()==0){
      if(boucleAmont()==0 || boucleAval()==1){
        while(boucleAmont()==0 || boucleAval()==0);
        nombreVoiture++;
      }
    }
    Wire.beginTransmission(0x20);             //Bit de start + adresse
    Wire.write(0xFE);                         //Trame
    Wire.endTransmission();                   //Bit de stop
    delay(1000);
  }

  if(boucleAmont()==1 && boucleAval()==0){
    Wire.beginTransmission(0x20);             //Bit de start + adresse
    Wire.write(0xFD);                         //Trame
    Wire.endTransmission();                   //Bit de stop
    delay(1000);
    while(boucleAval()==0 && boucleAmont()==1);
    if(boucleAmont()==0 || boucleAval()==0){
      while(boucleAmont()==0 || boucleAval()==0);
      nombreVoiture--;
      Wire.beginTransmission(0x20);             //Bit de start + adresse
      Wire.write(0xFE);                         //Trame
      Wire.endTransmission();                   //Bit de stop
      delay(1000);
    }
  }
 Serial.println("Nombre de voiture:");
 Serial.println(nombreVoiture,DEC);
}


