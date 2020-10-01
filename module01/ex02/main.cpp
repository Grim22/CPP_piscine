#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main()
{
    Zombie paul; // zombie created on stack
    Zombie* pat;
    ZombieEvent good_zombies; // event created on stack
    
    paul.set_name("paulo");
    paul.set_type("bad");
    paul.announce();
    
    good_zombies.setZombieType("good");
    pat = good_zombies.newZombie("patrick"); // zombie created on heap
    pat->announce();
    delete pat;
    
    good_zombies.randomChump(); // zombie created on stack
}