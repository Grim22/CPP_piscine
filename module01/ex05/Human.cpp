#include "Human.hpp"
#include <iostream>

Human::Human(void): brain()
{
}

Human::~Human(void)
{}

Brain&   Human::getBrain(void)
{
    return(this->brain);
}

std::string Human::identify()
{
    return(this->brain.identify());
}
