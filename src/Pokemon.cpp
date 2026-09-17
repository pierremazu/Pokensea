#include "../inc/Pokemon.hpp"
#include <iostream>

Pokemon::Pokemon(int id, string name, double maxHitPoint, double hitPoint, double attack, double defense, int evolution) : id(id),name(name),maxHitPoint(maxHitPoint),hitPoint(hitPoint),attack(attack),defense(defense),evolution(evolution){
    //Vérification PVs
    //Les PV max doivent être positifs
    if (this->maxHitPoint < 0){
        this->maxHitPoint = 0;
    }
    //les PV actuels doivent être entre 0 et les PV max
    if (this->hitPoint < 0){
        this->hitPoint = 0;
    }
    else if (this->hitPoint > this->maxHitPoint){
        this->hitPoint = this->maxHitPoint;
    }
    
    //std::cout << "Constructeur Pokémon : " << this->name << std::endl;
}

Pokemon::~Pokemon(){
    std::cout<<"Destructeur Pokémon : "<< name <<std::endl;
}

//affiche les informations du Pokémon sélectionné
void Pokemon::displayInfo() const{
    std::cout<<"ID : "<<id<<std::endl;
    std::cout<<"Nom : "<<name<<std::endl;
    std::cout<<"évolution numéro : "<<evolution<<std::endl;
    std::cout<<"PV max : "<<maxHitPoint<<std::endl;
    std::cout<<"PV actuels : "<<hitPoint<<std::endl;
    std::cout<<"attaque : "<<attack<<std::endl;
    std::cout<<"defense : "<<defense<<std::endl;
    std::cout<<"KO :"<<(isKO() ? "Oui" : "Non")<<std::endl;
}

int Pokemon::getId() const{
    return id;
}
std::string Pokemon::getName() const{
    return name;
}
int Pokemon::getEvolution()const{
    return evolution;
}
double Pokemon::getMaxHitPoint() const{
    return maxHitPoint;
}
double Pokemon::getHitPoint() const{
    return hitPoint;
}
double Pokemon::getAttack() const{
    return attack;
}
double Pokemon::getDefense() const{
    return defense;
}

//verifie si le pokemon est KO
bool Pokemon::isKO() const{
    return hitPoint <=0;
}

//annonce le KO
void Pokemon::announceKO(){
    std::cout << "Le Pokemon " << name
              << " est tombe au combat !"
              << std::endl;
}

//gestion dégâts reçus
void Pokemon::tookDamage(double damage){
    if (isKO() || damage < 0 ){
        return;
    }

    hitPoint -= damage;

    if (hitPoint < 0){
        hitPoint = 0;
    }

    std::cout << "Le Pokemon " << name << "a pris " << damage << "Dégâts ! "<<std::endl;
}

//le pokémon attaque un autre pokémon
void Pokemon::atkPokemon(Pokemon& cible){
    //vérifie l'attaquant
    if (isKO()){
        std::cout << name << "Ne peut pas attaquer, il est KO !"<<std::endl;
        return;
    }

    //vérification cible
    if (cible.isKO()){
        std::cout<<cible.name<<"est déjà KO !"<<std::endl;
        return;
    }
    //Calcul dégâts
    double damage = attack - cible.defense;

    if (damage <=0){
        std::cout << cible.name << "n'a pas subit de dégâts !"<<std::endl;
        return;
    }

    //On mémorise les PV avant l'attaque
    double previousHitPoint = cible.hitPoint;

    //on applique les dégats
    cible.tookDamage(damage);

    //On annonce le KO si la cible tombe à 0 PVs
    if (previousHitPoint > 0 && cible.isKO()){
        cible.announceKO();
    }
}