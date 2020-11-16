#ifndef CURE_H
# define CURE_H

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
    private:

    public:
        Cure(void);
        Cure(const Cure &copy);
        virtual ~Cure(void);
        Cure&  operator=(const Cure &copy);
        
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

// std::ostream & operator<<(std::ostream &o, const Cure &rhs);

#endif