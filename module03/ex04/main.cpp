#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap heidi("heid");
    heidi.beRepaired(20);
    heidi.takeDamage(10);
    heidi.rangedAttack("you");
    heidi.meleeAttack("you");

    std::cout << "---" << std::endl;

    ScavTrap paul("paulo");
    paul.takeDamage(200);
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
    Donald.ninjaShoebox(Joe);

    std::cout << "---" << std::endl;
    {
    SuperTrap benny("bigBen");
    SuperTrap hector("hp");
    hector.takeDamage(20);
    benny.ninjaShoebox(hector);
    benny.meleeAttack("stud");
    hector.vaulthunter_dot_exe("people");
    benny.rangedAttack("stud");
    hector = benny;
    hector.beRepaired(20);
    benny.beRepaired(20);
    }
    std::cout << "---" << std::endl;
}