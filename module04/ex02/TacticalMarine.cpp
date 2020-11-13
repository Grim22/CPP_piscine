#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine(void)
{
    std::cout << "Tactical Marine ready for battle !" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &copy)
{
    (void)copy;
    // std::cout << "TM Copy constructor called" << std::endl;
}

TacticalMarine::~TacticalMarine(void)
{
    std::cout << "Aaaargh..." << std::endl;
    // delete this;
}

TacticalMarine&   TacticalMarine::operator=(const TacticalMarine &rhs)
{
    (void)rhs;
    // std::cout << "Assignement operator called" << std::endl;
    return(*this);
}

// std::ostream & operator<<(std::ostream &o, const TacticalMarine &rhs)
// {
//     o << /*text*/ << std::endl;
//     return o;
// }

ISpaceMarine* TacticalMarine::clone() const
{
    ISpaceMarine *base_ptr = new TacticalMarine(*this);
    return base_ptr;
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with a chainsword *" << std::endl;
}