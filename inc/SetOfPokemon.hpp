#ifndef SETOFPOKEMON_HPP
#define SETOFPOKEMON_HPP

#include <vector>
#include "Pokemon.hpp"

class SetOfPokemon{
    protected:
        std::vector<Pokemon*> arrayOfPokemon;

    public:
        virtual ~SetOfPokemon();

        virtual Pokemon clonePokemon(int id) const = 0;

        //Empêche la copie de la collection de pointeurs.
        SetOfPokemon(const SetOfPokemon&) = delete;
        SetOfPokemon& operator=(const SetOfPokemon&) = delete;

    protected:
        SetOfPokemon();
};

#endif