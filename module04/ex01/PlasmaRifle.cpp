#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle(void): AWeapon("Plasma Rifle", 5, 21)
{
    // std::cout << "PlasmaRifle constructor called" << std::endl;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy): AWeapon(copy)
{}

PlasmaRifle::~PlasmaRifle(void)
{
    // std::cout << "PlasmaRifle Destructor called" << std::endl;
}

PlasmaRifle&   PlasmaRifle::operator=(const PlasmaRifle &rhs)
{
    // std::cout << "PlasmaRiffle Assignement operator called" << std::endl;
    this->AWeapon::operator=(rhs);
    return(*this);
}

void PlasmaRifle::attack(void) const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
