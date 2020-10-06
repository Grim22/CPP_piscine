#include "Human.hpp"
#include <iostream>

void Human::meleeAttack(std::string const & target)
{
    std::cout << "melee attack on: " << target << std::endl;
}
void Human::rangedAttack(std::string const & target)
{
    std::cout << "ranged attack on: " << target << std::endl;
}
void Human::intimidatingShout(std::string const & target)
{
    std::cout << "shouting attack on: " << target << std::endl;
}

int set_index(std::string const &action_name)
{
    if (action_name == "melee" || action_name == "meleeAttack")
        return 0;
    if (action_name == "ranged" || action_name == "rangedAttack")
        return 1;
    if (action_name == "shouting" || action_name == "intimidatingShout")
        return 2;
    else
        return -1;
}

void Human::action(std::string const & action_name, std::string const & target)
{
    int index;
    void (Human::*actions[3])(std::string const &target) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
    index = set_index(action_name);
    if (index == -1)
    {
        std::cout << "Unknown attack" << std::endl;
        return ;
    }
    (this->*actions[index])(target);
}