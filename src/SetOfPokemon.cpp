#include "C:/Users/pijef/Desktop/cplusplus/tp1/inc/SetOfPokemon.hpp"

SetOfPokemon::SetOfPokemon(){}

SetOfPokemon::~SetOfPokemon(){
    for (unsigned int i = 0; i < arrayOfPokemon.size(); ++i){
        delete arrayOfPokemon[i];
    }

    arrayOfPokemon.clear();
}