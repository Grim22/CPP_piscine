#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{}

HumanB::~HumanB(void)
{}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon; // taking the address of a reference gives you the address of the referent
}

void    HumanB::attack(void) const
{
    if (this->weapon == NULL)
        std::cout << "Please set a weapon first" << std::endl;
    else
        std::cout << std::uppercase << this->name << " attacks with his " << std::uppercase << this->weapon->getType() << std::endl;
}