#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time


ClapTrap::ClapTrap(const std::string &name): hit_points(100), max_hit_points(100),
energy_points(100), max_energy_points(100), level(1), name(name), melee_attack_damage(30),
ranged_attack_damage(20), armor_damage_reduction(5)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
    std::srand(std::time(NULL));
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap Assignement operator called" << std::endl;
    this->armor_damage_reduction = rhs.armor_damage_reduction;
    this->energy_points = rhs.energy_points;
    this->hit_points = rhs.hit_points;
    this->level = rhs.level;
    this->max_energy_points = rhs.max_energy_points;
    this->max_hit_points = rhs.max_hit_points;
    this->melee_attack_damage = rhs.melee_attack_damage;
    this->name = rhs.name;
    this->ranged_attack_damage = rhs.ranged_attack_damage;
    return(*this);
}

void    ClapTrap::rangedAttack(std::string const & target) const
{
    std::cout << "FR4G-TP " << this->name << " attacks " << target
    << " at range, causing " << this->ranged_attack_damage << " points of damage!" << std::endl;
}

void    ClapTrap::meleeAttack(std::string const & target) const
{
    std::cout << "FR4G-TP " << this->name << " melee-attacks " << target
    << ", causing " << this->melee_attack_damage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int taken;
    taken = amount - this->armor_damage_reduction;
    if (amount <= this->armor_damage_reduction)
        taken = 0;
    if (this->energy_points <= taken)
        taken = this->energy_points;
    this->energy_points -= taken;
    std::cout << "FR4G-TP " << this->name << " takes damage for " << taken << " points !(" << this->energy_points << " energy points remaining)" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
   unsigned int healed;

    if (this->energy_points + amount >= this->max_energy_points)
        healed = this->max_energy_points - this->energy_points;
    else
        healed = amount;
    this->energy_points += healed;
    std::cout << "FR4G-TP " << this->name << " is repaired for " << healed << " points !(" << this->energy_points << " energy points remaining)" << std::endl;
}
