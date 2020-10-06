#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string color, std::string name): color(color), name(name) 
{
    std::cout << "**pony " << this->name << " created**" << std::endl;
}

Pony::~Pony(void)
{
    std::cout << "**pony " << this->name << " destroyed**" << std::endl;
}

void    Pony::announce(void)
{
    std::cout << "Hello I'm " << this->name << ", my color is " << this->color << std::endl;
}