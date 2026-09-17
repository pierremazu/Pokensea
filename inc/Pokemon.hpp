#include <string>
using namespace std;

class Pokemon {
    private : 

        int id;
        string name;

        double hitPoint;
        double maxHitPoint;
        double attack;
        double defense;

        int evolution;

    public : 

        Pokemon(int id, string name, double maxHitPoint, double hitPoint, double attack, double defense, int evolution=0);

        ~Pokemon();
        
        //affichage des informations du pokémon
        void displayInfo() const;

        int getId() const;

        string getName() const;

        int getEvolution() const;

        double getMaxHitPoint() const;
        double getHitPoint() const;
        double getAttack() const;
        double getDefense() const;

        //Attaque un autre pokemon
        void atkPokemon(Pokemon& cible);

        //Retire des PVs
        void tookDamage(double damage);

        //Vérifie et enregistre les KOs
        bool isKO() const;
        //annonce le KO
        void announceKO();
};