#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap &rhs)
{
    ClapTrap::operator=(rhs);
    return(*this);
}

void    ScavTrap::rangedAttack(std::string const & target) const
{
    std::cout << "// ScavTrap rules ! // ";
    ClapTrap::rangedAttack(target);
}

void    ScavTrap::meleeAttack(std::string const & target) const
{
    std::cout << "// ScavTrap rules ! // ";
    ClapTrap::meleeAttack(target);
}

std::string challenges[5] = {"Tourner sur soi même", "Crier vive Trump", "Chanter la marseillaise", "Faire une déclaration d'amour a Sophie Vigier", "Braver le confinement"};

void    ScavTrap::challengeNewcomer() const
{
    std::cout << "Here is your challenge: " << challenges[std::rand() % 5] << std::endl;
}
