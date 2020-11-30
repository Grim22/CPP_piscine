#include "Intern.hpp"
#include <iostream>

Intern::Intern(void)
{
    std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(/* Param */)
{
    std::cout << "Param constructor called" << std::endl;
}

Intern::Intern(const Intern &copy):
/* assignements */
{
    std::cout << "Copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Destructor called" << std::endl;
}

Intern&   Intern::operator=(const Intern &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    /*assignements*/
    return(*this);
}

std::ostream & operator<<(std::ostream &o, const Intern &rhs)
{
    o << /*text*/ << std::endl;
    return o;
}
