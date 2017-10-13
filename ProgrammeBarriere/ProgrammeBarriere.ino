#include "fonction.h"           //Inclusion du fichier "fonction.h"
#include "arduino.h"            //Inclusion du fichier "arduino.h"
#include "affiche.h"            //Inclusion du fichier "affiche.h"
#include "I2C.h"                //Inclusion du fichier "I2C.h"
#include <Wire.h>               //Inclusion de la bibliothèque <Wire.h>

/*fonction setup executée une fois lors du démrrage de la carte*/
void setup() {
  Serial.begin(9600);           //Initialise la vitesse de transmission à 9600Bauds
  Wire.begin();                 //Initialise la bibliothèque Wire et joint
                                //le bus I2C au maître ou à l'esclave
  initI2C(122);                 //Initialisation du bus I2C à 122
}

/*fonction Loop exécutée en boucle dans le programme principal*/
void loop() {
  int tempo = 0, testTempo;                 //Tempo permettra d'attendre les 30 secondes en entrée
  static unsigned int nombreVoiture = 0;    //variable static permettant de compter le nombre de véhicules dans le parking
/*vérification d'un véhicule en entrée et temporisation*/
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
/*incrémente le nombre de véhicule seulement si la voiture rentre dans le parking*/
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
/*décrémente le nombre de véhicule seulement si la voiture sort dans le parking*/
    while(boucleAval()==0 && boucleAmont()==1);
    if(boucleAmont()==0 || boucleAval()==0){
      while(boucleAmont()==0 || boucleAval()==0);
      nombreVoiture--;
      fermer();
    }
  }
/*affiche au moniteur l'incrémentation et la décrémentation de l'accès parking*/
 Serial.print("Nombre de voiture:");
 Serial.println(nombreVoiture,DEC);
}


