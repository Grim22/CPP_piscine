#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main()
{
    // we create ZombieEvent and set its type
    ZombieEvent good_zombies;
    good_zombies.setZombieType("good");
    
    // we use newZombie
    // Zombie* is returned. We should allocate it dynamically
    // => allocation of a Zombie on the heap
    std::cout << std::endl;
    Zombie* pat;
    pat = good_zombies.newZombie("patrick");
    pat->announce();
    delete pat;
    std::cout << "[back to main]" << std::endl;
    
    // we use randomChump 
    // Zombie is not returned. No need to allocate it dynamically
    // => allocation of a Zombie on the stack
    std::cout << std::endl;
    good_zombies.randomChump();
    std::cout << "[back to main]" << std::endl;
    
    std::cout << std::endl;
}