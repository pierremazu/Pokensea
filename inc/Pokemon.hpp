#include <iostream>

#include <string>
using namespace std;

class Pokemon {
    private : 
        string name;

        double hitPoint;
        double maxHitPoint;
        double attack;
        double defense;

        int evolution;

        bool ko = false;

        static int numberOfPokemon;

    public : 

        int id;

        Pokemon(int id, string name, double maxHitPoint, double hitPoint, double attack, double defense, int evolution);

        ~Pokemon();
        
        // methode : affichage des infos du pokémon
        void displayInfo() const;

        //int getId() const;
        //string getName() const;
        double getMaxHitPoint() const;
        double getHitPoint() const;
        double getAttack() const;
        double getDefense() const;

        //int getNumberOfPokemon(); //pas const car s'applique à la classe, pas à l'état de l'objet (on utilise une variable statique)
        //int getEvolution() const;

        //Attaque un autre pokemon
        void atkPokemon(Pokemon& cible);

        //Retire des PVs
        void tookDamage(double damage);

        //Vérifie et enregistre les KOs
        bool isKO();
        //annonce le KO
        void announceKO();
};