#ifndef SUPERTRAP_H
# define SUPERTRAP_H
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include <string>
class FragTrap;
class ScavTrap;

class SuperTrap: public FragTrap, public NinjaTrap {

    public:
    SuperTrap(const std::string &name = "unnamed"); // default value given to parameter, so that constructor is a cannonical default constructor
    SuperTrap(const SuperTrap &copy);
    ~SuperTrap(void);
    SuperTrap&  operator=(const SuperTrap &copy);
    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
};

#endif