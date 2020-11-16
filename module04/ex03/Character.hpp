#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        AMateria *inventory[4]; 
        // "Of course, you’ll have to be able to support ANY AMateria in a Character’s inventory." -> pointer to AMateria is used
        int materia_num;
        std::string name;

    public:
        Character(void);
        Character(const std::string & name);
        Character(const Character &copy);
        virtual ~Character(void);
        Character&  operator=(const Character &copy);
        
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

std::ostream & operator<<(std::ostream &o, const Character &rhs);

#endif