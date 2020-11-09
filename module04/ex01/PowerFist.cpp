#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void): AWeapon("PowerFist", 50, 8)
{
    std::cout << "PowerFist constructor called" << std::endl;
}

PowerFist::PowerFist(const PowerFist &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

PowerFist::~PowerFist(void)
{
    std::cout << "PowerFist Destructor called" << std::endl;
}

PowerFist&   PowerFist::operator=(const PowerFist &rhs)
{
    std::cout << "PlasmaRiffle Assignement operator called" << std::endl;
    this->AWeapon::operator=(rhs);
    return(*this);
}

void PowerFist::attack(void) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
