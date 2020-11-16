#include "Ice.hpp"
#include <iostream>

Ice::Ice(void): AMateria("Ice")
{
    // std::cout << "Default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy): AMateria(copy)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Ice::~Ice(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Ice&   Ice::operator=(const Ice &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->AMateria::operator=(rhs);
    return(*this);
}

AMateria* Ice::clone() const
{
    AMateria *base_ptr = new Ice;
    *base_ptr = *this;
    return base_ptr;
    // return new Ice(*this) = the same
}


void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
    this->AMateria::use(target);
}
