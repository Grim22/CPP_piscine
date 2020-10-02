#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{}

HumanA::~HumanA(void)
{}

void    HumanA::attack(void) const
{
    std::cout << std::uppercase << this->name << " attacks with his " << std::uppercase << this->weapon.getType() << std::endl;
}