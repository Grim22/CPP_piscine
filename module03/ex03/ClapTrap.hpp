#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap{
    protected:
    unsigned int hit_points;
    unsigned int max_hit_points;
    unsigned int energy_points;
    unsigned int max_energy_points;
    unsigned int level;
    std::string name;
    unsigned int melee_attack_damage;
    unsigned int ranged_attack_damage;
    unsigned int armor_damage_reduction;

    public:
    ClapTrap(const std::string &name = "unknown");
    ClapTrap(const ClapTrap &copy);
    ~ClapTrap(void);
    ClapTrap&  operator=(const ClapTrap &copy);
    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif