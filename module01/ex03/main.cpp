#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

#define NUM 4

int main()
{
    ZombieHorde horde(NUM);
    horde.announce();
    std::cout << "[back to main]" << std::endl;
    // You must allocate all the Zombie objects in a single allocation
    // and release them when the ZombieHorde it destroyed.
}