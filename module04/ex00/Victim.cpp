#include "Victim.hpp"
#include <iostream>

Victim::Victim(const std::string &name): name(name)
{
    std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Victim::~Victim(void)
{
    std::cout << "Victim " << this->name << " just died for no apparent reason!!" << std::endl;
}

Victim&   Victim::operator=(const Victim &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->name = rhs.name;
    return(*this);
}

const std::string & Victim::get_name(void) const
{
    return(this->name);
}

void Victim::getPolymorphed() const
{
    std::cout << this->get_name() << " has been turned into a cute little sheep" << std::endl;
}

std::ostream & operator<<(std::ostream &o, const Victim &rhs)
{
    o << "I'm " << rhs.get_name() << " and I like otters" << std::endl;
    return o;
}
