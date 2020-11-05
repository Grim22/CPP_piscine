#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time

SuperTrap::SuperTrap(const std::string &name): ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5)
{
    std::cout << "SuperTrap Default constructor called" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &copy): ClapTrap(copy), FragTrap(copy), NinjaTrap(copy)
{
    std::cout << "SuperTrap Copy constructor called" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
    std::cout << "SuperTrap Destructor called" << std::endl;
}

SuperTrap&   SuperTrap::operator=(const SuperTrap &rhs)
{
    std::cout << "SuperTrap Assignement operator called" << std::endl;
    NinjaTrap::operator=(rhs);
    return(*this);
}

void    SuperTrap::rangedAttack(std::string const & target) const
{
    FragTrap::rangedAttack(target);
}

void    SuperTrap::meleeAttack(std::string const & target) const
{
    NinjaTrap::meleeAttack(target);
}
