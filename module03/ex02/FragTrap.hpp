#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include "ClapTrap.hpp"
#include <string>

class FragTrap: public ClapTrap {

    public:
    FragTrap(const std::string &name = "unknown"); // default value given to parameter, so that constructor can be used as a default constructor
    FragTrap(const FragTrap &copy);
    ~FragTrap(void);
    FragTrap&  operator=(const FragTrap &copy);
    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void vaulthunter_dot_exe(std::string const & target);
};

#endif