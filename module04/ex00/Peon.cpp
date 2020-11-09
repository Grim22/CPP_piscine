#include "Peon.hpp"
#include <iostream>

Peon::Peon(const std::string &name): Victim(name)
{
    std::cout << "Zog zog" << std::endl;
}

Peon::Peon(const Peon &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Peon::~Peon(void)
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->get_name() << " has been turned into a pink pony" << std::endl;
}

Peon&   Peon::operator=(const Peon &rhs)
{
    this->Victim::operator=(rhs);
    return(*this);
}
