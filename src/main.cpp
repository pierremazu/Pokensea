
#include "C:/Users/pijef/Desktop/cplusplus/tp1/inc/Pokedex.hpp"
#include <iostream>

int main(){
    try{
        Pokedex& dex = Pokedex::getInstance("..\\pokedex.csv");

        Pokemon p = dex.clonePokemon(25);
        p.displayInfo();
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
