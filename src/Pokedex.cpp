#include "C:/Users/pijef/Desktop/cplusplus/tp1/inc/Pokedex.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

Pokedex* Pokedex::instance = 0;

Pokedex& Pokedex::getInstance(const std::string& fileName){
    if (instance == 0){
        instance = new Pokedex(fileName);
    }

    return *instance;
}

Pokedex::Pokedex(const std::string& fileName): SetOfPokemon(){
    std::cout << "*** Constructeur du Pokedex ***" << std::endl;
    loadCSV(fileName);
}

void Pokedex::loadCSV(const std::string& fileName){
    std::ifstream file(fileName.c_str());
    if (!file.is_open()){
        throw std::runtime_error("Impossible d'ouvrir le fichier CSV : " + fileName);
    }

    std::string line;

    //Ignore en-tête
    std::getline(file, line);

    while (std::getline(file, line)){
        std::stringstream inputstringstream(line);
        std::string cell;
        std::vector<std::string> lineData;

        while (std::getline(inputstringstream, cell, ',')){
            lineData.push_back(cell);
        }

        //Les colonnes 0 à 11 doivent exister pour que le tout soit lu
        if (lineData.size() <= 11){
            std::cerr << "Ligne CSV ignorée : nombre de colonnes insuffisant."
                      << std::endl;
            continue;
        }

        try{
            int id = std::stoi(lineData.at(0));
            double hitPoint = std::stod(lineData.at(5));
            double attackValue = std::stod(lineData.at(6));
            double defenseValue = std::stod(lineData.at(7));
            int generation = std::stoi(lineData.at(11));

            Pokemon* pokemon = new Pokemon(id,lineData.at(1),hitPoint,attackValue,defenseValue,generation);

            arrayOfPokemon.push_back(pokemon);
        }
        catch (const std::exception& e){
            std::cerr << "Ligne CSV invalide : " << e.what() << std::endl;
        }
    }
}

Pokemon Pokedex::clonePokemon(int id) const{
    for (unsigned int i = 0; i < arrayOfPokemon.size(); ++i){
        if (arrayOfPokemon[i]->getId() == id){
            //Renvoie une copie
            return *arrayOfPokemon[i];
        }
    }

    throw std::runtime_error("Aucun Pokemon avec cet identifiant.");
}