#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

int main()
{

    ClapTrap heidi("heid");
    heidi.takeDamage(10);
    heidi.beRepaired(20);
    heidi.rangedAttack("you");
    heidi.meleeAttack("you");

    std::cout << "---" << std::endl;

    ScavTrap paul("paulo");
    paul.takeDamage(20);
    paul.beRepaired(20);
    paul.rangedAttack("you");
    paul.meleeAttack("you");
    paul.challengeNewcomer();
    paul.challengeNewcomer();

    std::cout << "---" << std::endl;
    FragTrap mike("mikee");
    mike.takeDamage(10);
    mike.beRepaired(20);
    mike.rangedAttack("you");
    mike.meleeAttack("you");
    mike.vaulthunter_dot_exe("you");
    mike.vaulthunter_dot_exe("you");

    std::cout << "---" << std::endl;

    NinjaTrap Donald("don");
    Donald.takeDamage(10);
    Donald.beRepaired(20);
    Donald.rangedAttack("you");
    Donald.meleeAttack("you");
    Donald.ninjaShoebox(mike);
    Donald.ninjaShoebox(heidi);
    Donald.ninjaShoebox(paul);
    NinjaTrap Joe("sleepyJoe");
    Joe.takeDamage(200);
    Donald.ninjaShoebox(Joe);
    std::cout << "---" << std::endl;
}