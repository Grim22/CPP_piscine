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
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "FragTrap Assignement operator called" << std::endl;
    ClapTrap::operator=(rhs);
    return(*this);
}

void    FragTrap::rangedAttack(std::string const & target) const
{
    std::cout << "// FragTrap rules ! // ";
    ClapTrap::rangedAttack(target);
}

void    FragTrap::meleeAttack(std::string const & target) const
{
    std::cout << "// FragTrap rules ! // ";
    ClapTrap::meleeAttack(target);
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
