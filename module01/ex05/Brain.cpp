#include "Brain.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

std::string Brain::identify()
{
    long int address;
    address = (long int)this;
    std::stringstream ss;
    ss << std::setbase(16) << std::setiosflags (std::ios::showbase | std::ios::uppercase) << address;
    return (ss.str());
}

Brain::Brain(void){}
Brain::~Brain(void){}