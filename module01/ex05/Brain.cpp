#include "Brain.hpp"
#include <ios> // std::hex std::uppercase std::showbase
#include <sstream> // std::stringstream
#include <iostream>

std::string Brain::identify() const
{
    long int address;
    address = (long int)this;
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::showbase << address;
    return (ss.str());
}

Brain::Brain(void){}
Brain::~Brain(void){}