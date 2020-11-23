#include "MiningBarge.hpp"
#include <iostream>

#include "IMiningLaser.hpp"

MiningBarge::MiningBarge(void): num_lasers(0)
{
    this->lasers[0] = NULL;
    this->lasers[1] = NULL;
    this->lasers[2] = NULL;
    this->lasers[3] = NULL;
    //std::cout << "Default constructor called" << std::endl;
}

MiningBarge::MiningBarge(const MiningBarge &copy): num_lasers(copy.num_lasers)
{
    this->lasers[0] = copy.lasers[0];
    this->lasers[1] = copy.lasers[1];
    this->lasers[2] = copy.lasers[2];
    this->lasers[3] = copy.lasers[3];
    //std::cout << "Copy constructor called" << std::endl;
}

MiningBarge::~MiningBarge(void)
{
    //std::cout << "Destructor called" << std::endl;
}

MiningBarge&   MiningBarge::operator=(const MiningBarge &rhs)
{
    this->lasers[0] = rhs.lasers[0];
    this->lasers[1] = rhs.lasers[1];
    this->lasers[2] = rhs.lasers[2];
    this->lasers[3] = rhs.lasers[3];
    this->num_lasers = rhs.num_lasers;
    return(*this);
}

void MiningBarge::equip(IMiningLaser* laser)
{
    if (this->num_lasers >= 4 || laser == NULL)
        std::cout << "Can't equip anymore laser (max 4)" << std::endl;
    else
    {
        this->lasers[num_lasers] = laser;
        num_lasers++;
    }
}

void MiningBarge::mine(IAsteroid* ast) const
{
    for (int i = 0; i < this->num_lasers; i++)
        this->lasers[i]->mine(ast);
}

