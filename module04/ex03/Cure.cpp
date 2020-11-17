#include "Cure.hpp"
#include <iostream>
#include "ICharacter.hpp"

Cure::Cure(void): AMateria("cure")
{
    // std::cout << "Default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(copy)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Cure&   Cure::operator=(const Cure &rhs)
{
    // std::cout << "Assignement operator called" << std::endl;
    this->AMateria::operator=(rhs);
    return(*this);
}

AMateria* Cure::clone() const
{
    AMateria *base_ptr = new Cure;
    *base_ptr = *this;
    return base_ptr;
    // return new Cure(*this) = the same
}


void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    this->AMateria::use(target);
}
