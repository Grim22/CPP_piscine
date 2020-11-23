#include "StripMiner.hpp"
#include <iostream>

#include "IAsteroid.hpp"

StripMiner::StripMiner(void)
{
    std::cout << "S_Miner constructor called" << std::endl;
}

StripMiner::StripMiner(const StripMiner &copy)
{
    (void)copy;
    //std::cout << "Copy constructor called" << std::endl;
}

StripMiner::~StripMiner(void)
{
    //std::cout << "Destructor called" << std::endl;
}

StripMiner&   StripMiner::operator=(const StripMiner &rhs)
{
    (void)rhs;
    //std::cout << "Assignement operator called" << std::endl;
    return(*this);
}

void StripMiner::mine(IAsteroid* asteroid)
{
    std::cout << "*mining deep... got " << asteroid->beMined(this) << "! *" << std::endl;
}
