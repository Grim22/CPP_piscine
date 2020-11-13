#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator(void)
{
    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &copy)
{
    (void)copy;
    // std::cout << "AT Copy constructor called" << std::endl;
}

AssaultTerminator::~AssaultTerminator(void)
{
    std::cout << "I'll be back..." << std::endl;
    // delete this;
}

AssaultTerminator&   AssaultTerminator::operator=(const AssaultTerminator &rhs)
{
    (void)rhs;
    // std::cout << "Assignement operator called" << std::endl;
    return(*this);
}

// std::ostream & operator<<(std::ostream &o, const AssaultTerminator &rhs)
// {
//     o << /*text*/ << std::endl;
//     return o;
// }

ISpaceMarine* AssaultTerminator::clone() const
{
    ISpaceMarine *base_ptr = new AssaultTerminator(*this);
    return base_ptr;
}

void AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainfists *" << std::endl;
}