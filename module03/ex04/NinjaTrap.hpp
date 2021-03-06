#ifndef NINJATRAP_H
# define NINJATRAP_H
#include "ClapTrap.hpp"
#include <string>
class FragTrap;
class ScavTrap;

class NinjaTrap: virtual public ClapTrap {

    public:
    NinjaTrap(const std::string &name = "unnamed");
    NinjaTrap(const NinjaTrap &copy);
    ~NinjaTrap(void);
    NinjaTrap&  operator=(const NinjaTrap &copy);
    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void ninjaShoebox(FragTrap &target) const;
    void ninjaShoebox(ScavTrap &target) const;
    void ninjaShoebox(NinjaTrap &target);
    void ninjaShoebox(const ClapTrap &target) const;
};

#endif