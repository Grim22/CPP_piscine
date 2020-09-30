#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    Zombie paul;
    Zombie* zombies;
    ZombieEvent event;
    
    paul.set_name("paulo");
    paul.set_type("bad");
    paul.announce();
    
    event.setZombieType("good");
    zombies = event.newZombie("patrick");
    zombies->announce();
    delete zombies;
    
    event.setZombieType("ok");
    event.randomChump();
}