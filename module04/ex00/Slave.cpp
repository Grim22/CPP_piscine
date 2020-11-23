#include "Slave.hpp"
#include <iostream>

Slave::Slave(const std::string &name): Victim(name)
{
    std::cout << "Miaou miaou" << std::endl;
}

Slave::Slave(const Slave &copy): Victim(copy)
{
    std::cout << "Copy constructor called" << std::endl;
}

Slave::~Slave(void)
{
    std::cout << "Kssss..." << std::endl;
}

void Slave::getPolymorphed() const
{
    std::cout << this->get_name() << " has been turned into a chiwawa" << std::endl;
}

Slave&   Slave::operator=(const Slave &rhs)
{
    this->Victim::operator=(rhs);
    return(*this);
}
