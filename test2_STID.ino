// programme pour envoyer et recevoir les trames pour un seul robot 

#include <string.h>

#define TIMEOUT_MS 10000     // temps d'attente de la réponse 10s

String trame ="";

signed int SeuilHautCommandMove = 1000;  // exemple seuil haut accepté
signed int SeuilBasCommandMove = -1000;   // exemple seuil bas accepté 

unsigned int seuilSpeed=10;        // seuil maximum vitesse 

signed int pos=0;        


void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
  while (!Serial.available()) {
    delay(50);
  }
 
  Serial.readStringUntil('\n'); // lit et vide la saisie
  Serial.println("Terminal actif, lancement de la fonction...");
  delay(200);

}

void loop() {
 
 
// appuyez sur Entrée pour démarrer une fois la fenetre du terminal est ouverte

moveCommand(-25); // robot recule 

moveCommand(70);  // robot avance 

getCommand("speed");   // récuperer la valeur de la vitesse 

getCommand("pos");    // récuperer la valeur de la position 

setCommand("speed",6);    // modifier la vitesse du robot 

    
}


void moveCommand(signed int distance){
  // envoyer la commande 
    if ( distance >SeuilBasCommandMove && distance <SeuilHautCommandMove ){
      trame="/01 move "+String(distance);

          Serial.println(trame); // envoi de la trame
          Serial.flush(); // s'assurer que tout est envoyé
    }

   lecture de la réponse du robot
          receiveCommand();
  
}


void getCommand(String donnee){
  // envoyer la commande 
  if (donnee=="pos" || donnee == "speed"){
        trame="/01 get "+donnee;
        Serial.println(trame); // envoi de la trame
        Serial.flush(); // s'assurer que tout est envoyé
  }
  // lecture de la réponse du robot
        receiveCommand();
}


void setCommand(String donnee, unsigned valeurSpeed){
  // envoyer la commande 
   if ( donnee=="speed" && valeurSpeed>0 && valeurSpeed<=10){
        trame="/01 set "+String(valeurSpeed);
        Serial.println(trame); // envoi de la trame
        Serial.flush(); // s'assurer que tout est envoyé
    
   }

 lecture de la réponse du robot
    receiveCommand();
}



void receiveCommand(){
    unsigned long startTime = millis();
    String reponse = "";
    
    while (millis() - startTime < TIMEOUT_MS) {
            
          while (Serial.available()) {
                 char c = Serial.read();
                 reponse += c;

                 // Option : si ta trame de réponse a un caractère de fin connu (ex: '\n')
                 if (c == '\n') {
                 Serial.println(reponse);
                 return;
                        }
                        
                 }
                             
                  delay(1); // petit délai pour ne pas bloquer complètement
                   }

                  // delai
                  Serial.println("reponse non recu");

}
