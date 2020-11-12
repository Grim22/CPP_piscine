#ifndef ISPACEMARINE_H
# define ISPACEMARINE_H

#include <iostream>
#include <string>

class ISpaceMarine
{
    private:

    public:
        virtual ~ISpaceMarine() {};
        virtual ISpaceMarine* clone() const = 0;
        // this method allows copy of an object, when derived class object is accessed through a pointer to base class object
        // (in these cases, we can't use the copy constructor / the assignation operator, as they do not exist in base class, and even if they do exist:
        // for the assignation operator: it cant be made virtual function and then redefined at derived class level, as the return type is not the same. So only assignation of base class will be accessible
        // for the copy constructor: it is not inherited
        virtual void battleCry() const = 0;
        virtual void rangedAttack() const = 0;
        virtual void meleeAttack() const = 0;
};

#endif