#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant(void): Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &copy): Enemy(copy)
{}

SuperMutant::~SuperMutant(void)
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    this->Enemy::takeDamage(damage - 3);
}

SuperMutant&   SuperMutant::operator=(const SuperMutant &rhs)
{
    // std::cout << "SM Assignement operator called" << std::endl;
    this->Enemy::operator=(rhs);
    return(*this);
}
