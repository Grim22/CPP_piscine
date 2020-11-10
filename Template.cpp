#include "${Class}.hpp"
#include <iostream>

${Class}::${Class}(void)
{
    std::cout << "Default constructor called" << std::endl;
}

${Class}::${Class}(const ${Class} &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

${Class}::~${Class}(void)
{
    std::cout << "Destructor called" << std::endl;
}

${Class}&   ${Class}::operator=(const ${Class} &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    /*assignements*/
    return(*this);
}

std::ostream & operator<<(std::ostream &o, const {$Class} &rhs)
{
    o << /*text*/ << std::endl;
    return o;
}
