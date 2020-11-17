#ifndef Ice_H
# define Ice_H

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice: public AMateria
{
    private:

    public:
        Ice(void);
        Ice(const Ice &copy);
        virtual ~Ice(void);
        Ice&  operator=(const Ice &copy);
        
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

// std::ostream & operator<<(std::ostream &o, const Ice &rhs);

#endif