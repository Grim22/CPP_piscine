#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time


FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap &rhs)
{
    //std::cout << "Assignement operator called" << std::endl;
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

void    FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->name << " attacks " << target
    << " at range, causing " << this->ranged_attack_damage << " points of damage!" << std::endl;
}

void    FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->name << " melee-attacks " << target
    << ", causing " << this->melee_attack_damage << " points of damage!" << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount)
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

void    FragTrap::beRepaired(unsigned int amount)
{
   unsigned int healed;

    if (this->energy_points + amount >= this->max_energy_points)
        healed = this->max_energy_points - this->energy_points;
    else
        healed = amount;
    this->energy_points += healed;
    std::cout << "FR4G-TP " << this->name << " is repaired for " << healed << " points !(" << this->energy_points << " energy points remaining)" << std::endl;
}

std::string attacks[5] = {"Hyper_drole_attack", "Vachement_fun_attack", "Des_barres_attack", "Borderlands_attack", "Hyperion attack"};

void    FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    if (this->energy_points < 25)
    {
        std::cout << "FR4G-TP " << this->name << " doesn't have enough energy to perform this attack" << std::endl;
        return ;
    }
    this->energy_points -= 25;
    std::cout << "FR4G-TP " << this->name << " " << attacks[std::rand() % 5] << " " << target
    << ", causing 25 points of damage! (" << this->energy_points << " energy points remaining)" << std::endl;
    
}
