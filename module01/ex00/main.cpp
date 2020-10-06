#include "Pony.hpp"
#include <iostream>

void    ponyOntheHeap(std::string color, std::string name)
{
    Pony pony(color, name);
    pony.announce();
}

void    ponyOntheStack(std::string color, std::string name)
{
    Pony *ptr;
    ptr = new Pony(color, name);
    ptr->announce();
    delete ptr;
}

int main()
{
    ponyOntheHeap("black", "jolly");
    std::cout << "[back to main]" << std::endl;
    ponyOntheStack("white", "jumper");
    std::cout << "[back to main]" << std::endl;
}