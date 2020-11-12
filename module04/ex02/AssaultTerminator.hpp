#ifndef AssaultTerminator_H
# define AssaultTerminator_H

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
    private:

    public:
        AssaultTerminator(void);
        AssaultTerminator(const AssaultTerminator &copy);
        virtual ~AssaultTerminator(void);
        virtual ISpaceMarine* clone() const;
        virtual void battleCry() const;
        virtual void rangedAttack() const;
        virtual void meleeAttack() const;
        AssaultTerminator&  operator=(const AssaultTerminator &copy);
};

std::ostream & operator<<(std::ostream &o, const AssaultTerminator &rhs);

#endif