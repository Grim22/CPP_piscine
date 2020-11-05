#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{

    public:
    ScavTrap(const std::string &name = "unnamed");
    ScavTrap(const ScavTrap &copy);
    ~ScavTrap(void);
    ScavTrap&  operator=(const ScavTrap &copy);
    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void challengeNewcomer() const;
};

#endif