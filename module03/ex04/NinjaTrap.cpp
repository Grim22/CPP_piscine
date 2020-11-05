#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time

NinjaTrap::NinjaTrap(const std::string &name): ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
    std::cout << "NinjaTrap Default constructor called" << std::endl;
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120;
    this->max_energy_points = 120;
    this->level = 1;
    this->melee_attack_damage = 60;
    this->ranged_attack_damage = 5;
    this->armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap(const NinjaTrap &copy): ClapTrap(copy)
{
    std::cout << "NinjaTrap Copy constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout << "NinjaTrap Destructor called" << std::endl;
}

NinjaTrap&   NinjaTrap::operator=(const NinjaTrap &rhs)
{
    std::cout << "NinjaTrap Assignement operator called" << std::endl;
    ClapTrap::operator=(rhs);
    return(*this);
}

void    NinjaTrap::rangedAttack(std::string const & target) const
{
    std::cout << "// NinjaTrap rules ! // ";
    ClapTrap::rangedAttack(target);
}

void    NinjaTrap::meleeAttack(std::string const & target) const
{
    std::cout << "// NinjaTrap rules ! // ";
    ClapTrap::meleeAttack(target);
}

void NinjaTrap::ninjaShoebox(FragTrap &target) const
{
    std::cout << "I hate Fragtraps... take that !" << std::endl;
    target.takeDamage(100);
}

void NinjaTrap::ninjaShoebox(ScavTrap &target) const
{
    std::cout << "Come join me !" << std::endl;
    target.beRepaired(10);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
    std::cout << "I give my life for you" << std::endl;
    target.beRepaired(this->energy_points);
    this->takeDamage(this->energy_points);
}

void NinjaTrap::ninjaShoebox(const ClapTrap &target) const
{
    std::cout << "Hello Master, please try your attack on me" << std::endl;
    target.meleeAttack(this->name);
}