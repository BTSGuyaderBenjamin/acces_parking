/*second programme qui permet de faire monter la barrière si le véhicule est détecté sur
 *la boucle Amont, referme la barrière au bout de 30 secondes et referme la barrière si la
 *voiture n'est plus détécté sur la boucle*/
#include "arduino.h"                    //Inclusion du fichier "arduino.h"
#include <Wire.h>                       //Inclusion de la bibliothèque <Wire.h>
#include "I2C.h"                        //Inclusion du fichier "I2C.h"

/*fonction setup executée une fois lors du démrrage de la carte*/
void setup()
{
  Serial.begin(9600);                   //Initialise la liaison à 9600Bauds
  Wire.begin();                         //Initialise la bibliothèque Wire et joint
                                        //le bus I2C au maître ou à l'esclave
  initI2C(122);                         //Initialisation du bus I2C à 122
}

/*fonction Loop exécutée en boucle dans le programme principal*/
void loop() 
{
  int variable;                         //Déclaration d'une variable de type entier
  int valeur;                           //Déclaration d'une variable de type entier
  Wire.requestFrom(0x20, 1);            //Utilisé par le maître pour demander des octets à partir d'un périphérique esclave
                                        //avec l'adresse et la quantité d'octet
  while(Wire.available())               //Renvoie le nombre d'octets disponibles pour la récupération avec read ()
  {
    variable = Wire.read();             //variable recupère la valeur de Wire.read
    Serial.print((variable & 0x20)>>5); //Masque, ET bit à bit et décalage à droite du nombre de bits spécifiés pour avoir 0 ou 1
  }
  valeur = (variable & 0x20)>>5;        //valeur prend donc la valeur de 0 ou 1 grâce au décalage
  delay(1000);                          //Delais de 1000ms
  if(valeur==0)                         //Si valeur est égal à 0, donc si la boucle Amont détecte un véhicule
  {                                     //Programme pour ouvrir la barrière
    Wire.beginTransmission(0x20);       //Bit de start + adresse
    Wire.write(0xFD);                   //Trame pour ouvrir la barrière
    Wire.endTransmission();             //Bit de stop
    delay(30000);                       //Delais de 30000ms
  }                                     //On sort ensuite du if pour refermer la barrière
  Wire.beginTransmission(0x20);         //Bit de start + adresse
  Wire.write(0xFE);                     //Trame pour fermer la barrière
  Wire.endTransmission();               //Bit de stop
  delay(1000);                          //Delais de 1000ms
}

