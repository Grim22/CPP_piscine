#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>

class FragTrap{
    private:
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
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &copy);
    ~FragTrap(void);
    FragTrap&  operator=(const FragTrap &copy);
    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const & target);
};

#endif