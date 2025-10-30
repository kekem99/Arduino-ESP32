// programme pour automatiser le test de commande "move".

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

moveCommand(70); // robot recule 



    
}


void moveCommand(signed int distance){
  String receivedMsg="";
  String etatReponse="";

  String reponseUtilisateur = "";
  // envoyer la commande 
    if ( distance >SeuilBasCommandMove && distance <SeuilHautCommandMove ){
      trame="/01 move "+String(distance);
          Serial.print("commande envoyée : ");
          Serial.println(trame); // envoi de la trame
          Serial.flush(); // s'assurer que tout est envoyé
    }

//   lecture de la réponse du robot
         receivedMsg= receiveCommand();

//   traitement de la commande
          etatReponse=traitementReponsemove(receivedMsg);

         
     
      if ( etatReponse=="OK" && distance<0){
             Serial.println("le robot a-t-il reculé ? ");
             while (!Serial.available()) {
                // On attend 
                }
             while (Serial.available()) {
             char c = Serial.read();
             reponseUtilisateur += c;
              delay(2);  // petit délai pour laisser venir les caractères suivants
             }
            if ( reponseUtilisateur== "oui\n")  Serial.println("test validé");
             
          }
          

          if ( etatReponse=="OK" && distance>0){
             Serial.println("le robot a-t-il avancé ? ");
             while (!Serial.available()) {
                // On attend 
                }
             while (Serial.available()) {
             char c = Serial.read();
             reponseUtilisateur += c;
              delay(2);  // petit délai pour laisser venir les caractères suivants
             }
            if ( reponseUtilisateur== "oui\n")  Serial.println("test validé");


             
          }

            if ( etatReponse=="RJ"){
             Serial.println("la commande a été rejetée ");
          }







}





String receiveCommand(){
    unsigned long startTime = millis();
    String reponse = "";
    
    while (millis() - startTime < TIMEOUT_MS) {
            
          while (Serial.available()) {
                 char c = Serial.read();
                 reponse += c;

                 // Option : si ta trame de réponse a un caractère de fin connu (ex: '\n')
                 if (c == '\n') {
                 Serial.print("reponse recue : ");
                 Serial.println(reponse);
                 return reponse;
                        }
                        
                 }
                             
                  delay(1); // petit délai pour ne pas bloquer complètement
                   }

                  // delai
                  Serial.println("reponse non recu");
                  return "";

}
String traitementReponsemove(String reponse){
  String donneeReponse="";
  int i=0;
 if (reponse.length() > 0){
  
  while (i < reponse.length()) {
    
    char c = reponse[i];  // accès au i-ème caractère
    if ( c == ' '){
      donneeReponse=donneeReponse+reponse[i+4]+reponse[i+5];
      Serial.println("la reponse est : "+donneeReponse);
      i=reponse.length();
      
  }
  
  i++;
  
  }
 return donneeReponse;

 }

 
}
