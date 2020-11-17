#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void):
_type("unset"), _xp(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type):
_type(type), _xp(0)
{
    // std::cout << "Param constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy):
_type(copy._type), _xp(copy._xp)
{
    // std::cout << "Copy constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
    // std::cout << "Destructor called" << std::endl;
}

AMateria&   AMateria::operator=(const AMateria &rhs)
{
    // While assigning a Materia to another, copying the type doesn’t make sense...
    // -> AMateria object itsel will not be assigned: only derived type will, so their types will necessarly be the same
    // std::cout << "Assignement operator called" << std::endl;
    this->_xp = rhs._xp;
    return(*this);
}

std::string const & AMateria::getType() const //Returns the materia type
{
    return this->_type;
}

unsigned int AMateria::getXP() const //Returns the Materia's XP
{
    return this->_xp;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    this->_xp += 10;
}
