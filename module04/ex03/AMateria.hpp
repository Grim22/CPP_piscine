#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include <string>

#include "ICharacter.hpp";

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

std::ostream & operator<<(std::ostream &o, const AMateria &rhs);

#endif