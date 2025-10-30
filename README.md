# Arduino-ESP32
Test Robot

version Arduino : 1.8.19

carte de développement  : esp32 dev module


test2_STID.ino        

Pour tester le programme : 
-	Ouvrir le terminal série et appuyer sur la touche « OK » 
-	Le programme démarre et envoie la première commande « moveCommand(-25); » , c’est donc la trame « /01 move -25 ».
-	Délais d’attente d’une réponse est de 10 s
-	Dans cet intervalle-là, on peut envoyer une réponse sur le terminal exemple : @ 01 OK 0
-	Dans le cas où aucune réponse n’est reçue, un message est affiché sur le terminal « réponse non reçu ».
  
Liste des réponses ordonnée selon les commandes envoyées dans le programme : 
-	@ 01 OK 0
-	@ 01 OK 0
-	@ 01 OK 4
-	@ 01 OK 550
-	@ 01 OK 0


test3_STID.ino

Pour tester le programme : 
-	Ouvrir le terminal série et appuyer sur la touche « OK » 
-	Le programme démarre et envoie la première commande « moveCommand(-25); » , c’est donc la trame « /01 move -25 ».
-	Délais d’attente d’une réponse est de 10 s
-	Dans cet intervalle-là, on peut envoyer une réponse sur le terminal exemple : @ 01 OK 0
- observez le robot 
- au niveau du terminal le programme demande à l’utilisateur si le robot a reculé.
- envoyer la réponse « oui ».
- au niveau du terminal le programme affirme que le « test est validé ».
