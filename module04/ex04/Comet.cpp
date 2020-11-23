#include "Comet.hpp"
#include <iostream>

Comet::Comet(void): name("Comet")
{
    std::cout << "Comet constructor called" << std::endl;
}

Comet::Comet(const Comet &copy): name(copy.name)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Comet::~Comet(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Comet&   Comet::operator=(const Comet &rhs)
{
    //std::cout << "Assignement operator called" << std::endl;
    this->name = rhs.name;
    return(*this);
}

std::string Comet::beMined(StripMiner *s_miner) const
{
    (void)s_miner;
    return "Tartarite";
}

std::string Comet::beMined(DeepCoreMiner *dc_miner) const
{
    (void)dc_miner;
    return "Meium";
}

std::string Comet::getName() const
{
    return this->name;
}
