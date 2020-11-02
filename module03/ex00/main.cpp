#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap pat("Patrick");
    pat.meleeAttack("target");
    std::cout << "---" << std::endl;
    pat.rangedAttack("target");
    std::cout << "---" << std::endl;
    pat.vaulthunter_dot_exe("target");
    pat.vaulthunter_dot_exe("target");
    pat.vaulthunter_dot_exe("target");
    pat.vaulthunter_dot_exe("target");
    pat.vaulthunter_dot_exe("target");
    std::cout << "---" << std::endl;
    pat.beRepaired(20);
    pat.beRepaired(200);
    std::cout << "---" << std::endl;
    pat.takeDamage(10);
    pat.takeDamage(1);
    pat.takeDamage(200);
    std::cout << "---" << std::endl;
    FragTrap mike(pat);
    mike.beRepaired(20);
}