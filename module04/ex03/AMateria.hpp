#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include <string>

class ICharacter; // complete type not needed. Major problem of recursive inclusion if #include "ICharacter.hpp" instead

class AMateria
{
    private:
        std::string _type;
        unsigned int _xp;

    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(const AMateria &copy);
        virtual ~AMateria(void);
        AMateria&  operator=(const AMateria &copy);

        std::string const & getType() const; //Returns the materia type
        unsigned int getXP() const; //Returns the Materia's XP
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif