#include "C:/Users/pijef/Desktop/cplusplus/tp1/inc/Pokemon.hpp"
#include <iostream>
#include <algorithm>


Pokemon::Pokemon(int id, string name, double maxHitPoint, double hitPoint, double attack, double defense, int evolution) : id(id),name(name),maxHitPoint(maxHitPoint),hitPoint(hitPoint),attack(attack),defense(defense),evolution(evolution){
    //Vérification PVs actuels
    if (this->hitPoint < 0){
        this->hitPoint = 0;
    }
    else if (this->hitPoint > maxHitPoint){
        this->hitPoint = this->maxHitPoint;
    }
    
    std::cout << "Et voici le constructeur" << std::endl;
}

Pokemon::~Pokemon(){
    std::cout<<"Et voilà le destructeur"<<std::endl;
}

//affiche les informations du Pokémon sélectionné
void Pokemon::displayInfo() const{
    std::cout<<"ID : "<<id<<std::endl;
    std::cout<<"Nom : "<<name<<std::endl;
    std::cout<<"PV max : "<<maxHitPoint<<std::endl;
    std::cout<<"PV actuels : "<<hitPoint<<std::endl;
    std::cout<<"attaque : "<<attack<<std::endl;
    std::cout<<"defense : "<<defense<<std::endl;
    std::cout<<"évolution numéro : "<<evolution<<std::endl;
    std::cout<<"KO :"<<(ko ? "Oui" : "Non")<<endl;
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
//int Pokemon::getNumberOfPokemon(){return numberOfPokemon;}

//verifie si le pokemon est KO
bool Pokemon::isKO(){
    return hitPoint <=0;
}

//annonce le KO
void Pokemon::announceKO(){
    if (isKO() && !ko){
        ko = true;

        cout << "Le Pokemon"<< name <<" est tombé au combat !"<<endl;
    }
}

//gestion dégâts reçus
void Pokemon::tookDamage(double damage){
    //si KO, ne peut pas recevoir de dégâts
    if (ko || damage <= 0){
        return;
    }
    hitPoint -= damage;

    //PV ne peuvent pas être négatifs
    if (hitPoint < 0){
        hitPoint = 0;
    }

    cout << "Le Pokémon"<< name << " a pris" << damage << " dégats !"<<endl;
}

//le pokémon attaque un autre pokémon
void Pokemon::atkPokemon(Pokemon& cible){
    //vérifie si le pokémon
}