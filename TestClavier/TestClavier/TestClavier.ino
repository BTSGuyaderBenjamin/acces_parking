
      /*                   clavier.ino 
            découverte du clavier matriciel 16 touches 
      
      lignes en 38 à 44 d'Arduino (paires seulement) 
      colonnes en 46 à 52 
      */ 
      
      #include <Keypad.h> // inclusion de la librairie pour clavier matriciel 
      //--- Constantes utilisées avec le clavier 4x4 
      const byte LIGNES = 4;            // 4 lignes 
      const byte COLONNES = 4;       // 4 colonnes 
      
      // déclaration des broches --- 
      const int L1=38; 
      const int L2=40; 
      const int L3=42; 
      const int L4=44; 
      
      const int C1=46; 
      const int C2=48; 
      const int C3=50; 
      const int C4=52; 
      
      //--- Définition des touches 
      char touches[LIGNES][COLONNES] = { 
            {'1','2','3','A'}, 
            {'4','5','6','B'}, 
            {'7','8','9','C'}, 
            {'*','0','#','D'} 
      }; 
      
      // tableaux de lignes et colonnes 
      byte BrochesLignes[LIGNES] = {L1, L2, L3, L4}; 
      byte BrochesColonnes[COLONNES] = {C1, C2, C3, C4}; 
      
      char touche; // variable de stockage de la valeur de la touche appuyée 
      
      // création d'un objet keypad = initialisation clavier 
      Keypad clavier = Keypad( makeKeymap(touches), BrochesLignes, BrochesColonnes, LIGNES, COLONNES ); 
      // les broches de lignes sont automatiquement configurées en ENTREE avec pullup interne activé 
      // les broches de colonnes sont automatiquement configurées en SORTIE 
      
      void setup()             { 
          Serial.begin(9600); 
          delay(10); // pause rapide pour laisser temps initialisation 
      
            Serial.println("init OK") ; // affiche la chaîne texte - message de test 
            delay(2000); // pause de 2 secondes 
      } // fin de la fonction setup() 
      
      void loop()            { 
            touche = clavier.getKey(); // lecture de la touche appuyée 
            if (touche != NO_KEY){ // si une touche a été frappée -- gestion de la touche appuyée 
                  Serial.print(touche); 
                  Serial.print(" "); 
                  delay(300); // pause entre 2 appuis 
            }             // fin gestion de la touche appuyée 
      } 
