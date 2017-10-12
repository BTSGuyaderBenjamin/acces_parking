/*premier programme qui permet de faire monter et descendre la barrière 11/10/2017*/
#include "arduino.h"                    //Inclusion du fichier "arduino.h"
#include <Wire.h>                       //Inclusion de la bibliothèque <Wire.h>
#include "I2C.h"                        //Inclusion du fichier "I2C.h"


/*fonction setup executée une fois lors du démrrage de la carte*/
void setup()                            
{
  Wire.begin();                         //Initialise la bibliothèque Wire et joint
                                        //le bus I2C au maître ou à l'esclave
  initI2C(122);                         //Initialisation du bus I2C à 122
}

/*fonction Loop exécutée en boucle dans le programme principal*/
void loop()                             
{
  Wire.beginTransmission(0x20);         //Bit de start + adresse
  Wire.write(0xFD);                     //Trame d'ouverture de la barrière
  Wire.endTransmission();               //Bit de stop
  delay(1000);                          //Delais de 1000ms
  Wire.beginTransmission(0x20);         //Bit de start + adresse
  Wire.write(0xFE);                     //Trame de fermeture de la barrière
  Wire.endTransmission();               //Bit de stop
  delay(1000);                          //Delais de 1000ms

}

