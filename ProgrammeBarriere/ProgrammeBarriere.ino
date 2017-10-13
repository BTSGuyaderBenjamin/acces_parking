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
  static unsigned int nombreVoiture = 0;
  
  if(boucleAmont()==0 && boucleAval()==1){
    testTempo=1;
    if(validation()==0){
      ouvrir();
      while(boucleAmont()==0 && boucleAval()==1 && testTempo==1){
        tempo++;
        delay(30);
        if(tempo == 1000){
          testTempo=0;
        }
      }
   }
    if(boucleAmont()==1 || boucleAval()==0){
      if(boucleAmont()==0 || boucleAval()==1){
        while(boucleAmont()==0 || boucleAval()==0);
        nombreVoiture++;
      }
    }
    fermer();
 }

  if(boucleAmont()==1 && boucleAval()==0){
    ouvrir();
    while(boucleAval()==0 && boucleAmont()==1);
    if(boucleAmont()==0 || boucleAval()==0){
      while(boucleAmont()==0 || boucleAval()==0);
      nombreVoiture--;
      fermer();
    }
  }
 Serial.print("Nombre de voiture:");
 Serial.println(nombreVoiture,DEC);
}


