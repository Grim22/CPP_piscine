#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void): AWeapon("PowerFist", 8, 50)
{
    std::cout << "PowerFist constructor called" << std::endl;
}

PowerFist::PowerFist(const PowerFist &copy): AWeapon(copy)
{}

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
