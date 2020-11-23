#include "DeepCoreMiner.hpp"
#include <iostream>

#include "IAsteroid.hpp"

DeepCoreMiner::DeepCoreMiner(void)
{
    std::cout << "DC_Miner constructor called" << std::endl;
}

DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner &copy)
{
    (void)copy;
    //std::cout << "Copy constructor called" << std::endl;
}

DeepCoreMiner::~DeepCoreMiner(void)
{
    //std::cout << "Destructor called" << std::endl;
}

DeepCoreMiner&   DeepCoreMiner::operator=(const DeepCoreMiner &rhs)
{
    (void)rhs;
    //std::cout << "Assignement operator called" << std::endl;
    return(*this);
}

void DeepCoreMiner::mine(IAsteroid* asteroid)
{
    std::cout << "*mining deep... got " << asteroid->beMined(this) << "! *" << std::endl;
}
