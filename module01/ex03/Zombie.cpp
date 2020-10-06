#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
    this->type = "undefined";
    this->name = "undefined";
    std::cout << "**zombie created**" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "**" << this->name << " destroyed**" << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout << "hello, i'm " << this->name << " (type:" << this->type << ")" << std::endl;
}

void    Zombie::set_name(std::string name)
{
    this->name = name;
}

void    Zombie::set_type(std::string type)
{
    this->type = type;
}