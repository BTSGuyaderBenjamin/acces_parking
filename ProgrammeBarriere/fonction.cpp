#include "fonction.h"         //Inclusion du fichier "fonction.h"
#include "arduino.h"          //Inclusion du fichier "arduino.h"
#include "affiche.h"          //Inclusion du fichier "affiche.h"
#include <Wire.h>             //Inclusion de la bibliothèque <Wire.h>

int boucleAmont(){            //Fonction boucleAmont qui renvoie une valeur de type entier et qui n'accepte aucun paramètre
  int variableAmont;          //Déclaration d'une variable de type entier
  Wire.requestFrom(0x20, 1);  //Utilisé par le maître pour demander des octets à partir d'un périphérique esclave avec l'adresse et la quantitée d'octet
  while(Wire.available())     //Renvoie le nombre d'octets disponibles pour la récupération avec read ()
  { 
    variableAmont = Wire.read();                  //Wire.read récupère la valeur de variableAmont
    variableAmont = (variableAmont & 0x20)>>5;    //Opérateur logique 'Et' bit à bit avec variableAmont et décalage sur 5 bits pour ne récuprer que des valeurs 0 / 1   
  } 
  return variableAmont;       //On retourne la valeur de variableAmont
}

int boucleAval(){             //Fonction boucleAval qui renvoie une valeur de type entier et qui n'accepte aucun paramètre
  int variableAval;           //Déclaration d'une variable de type entier
  Wire.requestFrom(0x20, 1);  //Utilisé par le maître pour demander des octets à partir d'un périphérique esclave avec l'adresse et la quantitée d'octet
  while(Wire.available())     //Renvoie le nombre d'octets disponibles pour la récupération avec read ()
  { 
    variableAval = Wire.read();                   //Wire.read prend la valeur de variableAval  
    variableAval = (variableAval & 0x40)>>6;      //Opérateur logique 'Et' bit à bit avec variableAval et décalage sur 6 bits pour ne récuprer que des valeurs 0 / 1
  } 
  return variableAval;        //On retourne la valeur de variableAval  
}

int validation(){             //Fonction validation qui renvoie une valeur de type entier et qui n'accepte aucun paramètre
  int variableValidation;     //Déclaration d'une variable de type entier
  Wire.requestFrom(0x21, 1);  //Utilisé par le maître pour demander des octets à partir d'un périphérique esclave avec l'adresse et la quantitée d'octet
  while(Wire.available()){    //Renvoie le nombre d'octets disponibles pour la récupération avec read ()
    variableValidation = Wire.read();                     //Wire.read prend la valeur de variableValidation
    variableValidation = (variableValidation & 0x01);     //Opérateur logique 'Et' bit à bit avec variableValidation
  }
  return variableValidation;  //On retourne la valeur de variableValidation
}

void ouvrir(){                //Fonction ouvrir qui ne renvoie rien et qui n'accepte aucun paramètre
    Wire.beginTransmission(0x20);                 //Bit de start + adresse
    Wire.write(0xFD);                             //Trame pour ouvrir la barrière
    Wire.endTransmission();                       //Bit de stop
    delay(1000);                                  //Delais de 1000ms (1s)
}

void fermer(){              //Fonction fermer qui ne renvoie rien et qui n'accepte aucun paramètre
    Wire.beginTransmission(0x20);             //Bit de start + adresse
    Wire.write(0xFE);                         //Trame
    Wire.endTransmission();                   //Bit de stop
    delay(1000);
}

