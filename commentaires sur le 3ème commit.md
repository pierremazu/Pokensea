## commentaires sur le 3ème commit:

- manque d'un readme.md dans le git et d'un diagramme de classe 

- création des Pokémons incorrecte dans Pokedex.cpp: maxHitPoint prend la valeur des Hitpoints (correct) mais HitPoint prend la valeur d'attaque, l'attaque la valeur de défense…, il faut modifier les valeurs données pour correspondre au constructeur. De plus la valeur de génération est récupérée mais n'est pas un atribut de la classe Pokemon

- vérification des PV max devrait vérifier qu'ils sont supérieurs ou égaux à 1 (un Pokemon ayant un maxHitpoint de 0 n'est pas cohérent)

- l'attribut évolution est incorrect car mis à 0 pour tous les Pokémons

- chaque méthode devrait remplir une fonction spécifique, les méthodes atkPokemon et tookDamage ne devraient pas causer d'affichage console, ou alors appeler une autre méthode pour le faire (comme avec announceKO)

- pourrait ajouter des commentaires pour expliciter le sens des différentes classes

- au contraire certains commentaires sont superflus ou pas assez poussés:  
    //Calcul dégâts  
    double damage = attack - cible.defense;  
on pourrait soit retirer le commentaire soit expliquer la méthode de calcul de dégâts (bien qu'elle soit assez simple ici)  

- faire attention à l'affichage console, il manque des espaces pour certains messages:  
NidorinaNe peut pas attaquer, il est KO !  

- éviter les accents dans les messages consoles (peuvent apparaître incorrectement):  
Le Pokemon Nidorinaa pris 39D├®g├óts !  