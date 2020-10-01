#include "Human.hpp"
#include <iostream>

Human::Human(void): brain()
{
}

Human::~Human(void)
{}

const Brain&   Human::getBrain(void) const
{
    return(this->brain);
}

std::string Human::identify() const
{
    return(this->brain.identify());
}
