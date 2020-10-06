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
    Zombie* pat[2];
    pat[0] = good_zombies.newZombie("patrick");
    pat[0]->announce();
    pat[1] = good_zombies.newZombie("paddy");
    pat[1]->announce();
    delete pat[0];
    delete pat[1];
    std::cout << "[back to main]" << std::endl;
    
    // we use randomChump 
    // Zombie is not returned. No need to allocate it dynamically
    // => allocation of a Zombie on the stack
    std::cout << std::endl;
    good_zombies.randomChump();
    std::cout << "[back to main]" << std::endl;
    
    std::cout << std::endl;
}