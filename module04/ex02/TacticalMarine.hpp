#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
    private:

    public:
        TacticalMarine(void);
        TacticalMarine(const TacticalMarine &copy);
        virtual ~TacticalMarine(void);
        virtual ISpaceMarine* clone() const;
        virtual void battleCry() const;
        virtual void rangedAttack() const;
        virtual void meleeAttack() const;
        TacticalMarine&  operator=(const TacticalMarine &copy);
};

std::ostream & operator<<(std::ostream &o, const TacticalMarine &rhs);

#endif