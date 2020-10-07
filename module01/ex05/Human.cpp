#include "Human.hpp"
#include <iostream>

Human::Human(void): brain()
{
    std::cout << "human created" << std::endl;
}

Human::~Human(void)
{
    std::cout << "Human destroyed" << std::endl;
}

const Brain&   Human::getBrain(void) const
{
    return(this->brain);
}

std::string Human::identify() const
{
    return(this->brain.identify());
}
