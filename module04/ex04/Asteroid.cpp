#include "Asteroid.hpp"
#include <iostream>

Asteroid::Asteroid(void): name("Asteroid")
{
    std::cout << "Asteroid constructor called" << std::endl;
}

Asteroid::Asteroid(const Asteroid &copy): name(copy.name)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Asteroid::~Asteroid(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Asteroid&   Asteroid::operator=(const Asteroid &rhs)
{
    //std::cout << "Assignement operator called" << std::endl;
    this->name = rhs.name;
    return(*this);
}

std::string Asteroid::beMined(StripMiner *s_miner) const
{
    (void)s_miner;
    return "Flavium";
}

std::string Asteroid::beMined(DeepCoreMiner *dc_miner) const
{
    (void)dc_miner;
    return "Dragonite";
}

std::string Asteroid::getName() const
{
    return this->name;
}
