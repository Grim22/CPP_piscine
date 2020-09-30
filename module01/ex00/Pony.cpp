#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string color, std::string name, std::string origin, std::string fav_meal, int age)
: color(color), name(name), origin(origin), fav_meal(fav_meal), age (age) 
{
    std::cout << "pony " << this->name << " created" << std::endl;
}

Pony::~Pony(void)
{
    std::cout << "pony " << this->name << " destroyed" << std::endl;
}