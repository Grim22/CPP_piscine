#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
    // private:
    // unsigned int hit_points;
    // unsigned int max_hit_points;
    // unsigned int energy_points;
    // unsigned int max_energy_points;
    // unsigned int level;
    // std::string name;
    // unsigned int melee_attack_damage;
    // unsigned int ranged_attack_damage;
    // unsigned int armor_damage_reduction;

    public:
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &copy);
    ~ScavTrap(void);
    ScavTrap&  operator=(const ScavTrap &copy);
    void rangedAttack(std::string const & target);
    void meleeAttack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void challengeNewcomer();
};

#endif