#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include "SetOfPokemon.hpp"
#include <string>

class Pokedex : public SetOfPokemon{
private:
    static Pokedex* instance;
    explicit Pokedex(const std::string& fileName);
    void loadCSV(const std::string& fileName);

public:
    static Pokedex& getInstance(const std::string& fileName);

    Pokemon clonePokemon(int id) const;
};

#endif