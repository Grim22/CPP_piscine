#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion(void): Enemy(80, "RadScorpion")
{
    std::cout << "*click click click*" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &copy): Enemy(copy)
{}

RadScorpion::~RadScorpion(void)
{
    std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion&   RadScorpion::operator=(const RadScorpion &rhs)
{
    // std::cout << "SM Assignement operator called" << std::endl;
    this->Enemy::operator=(rhs);
    return(*this);
}
