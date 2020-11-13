#ifndef ISQUAD_H
# define ISQUAD_H

#include <iostream>
#include <string>

#include "ISpaceMarine.hpp" //"complete type" needed for when using delete on pointers to ISpaceMarine objects (error message: incomplete type...)

class ISquad
{
    public:
        // doesnt need any constructor, as it cant be instanciated
        virtual ~ISquad(void) {};
        // needs a virtual destructor, just like any base class (else, call to the most derived destructor will not be made)
        virtual int getCount() const = 0;
        virtual ISpaceMarine* getUnit(int) const = 0;
        virtual int push(ISpaceMarine*) = 0;
};


#endif