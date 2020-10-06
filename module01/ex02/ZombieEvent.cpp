#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time

ZombieEvent::ZombieEvent(void)
{
    this->type = "not defined";
    std::cout << "**event created**" << std::endl;
}

ZombieEvent::~ZombieEvent(void)
{
    std::cout << "**event destroyed**" << std::endl;
}

void    ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
}

// zombie* is returned. We use a pointer that we allocate and then delete in the main
Zombie  *ZombieEvent::newZombie(std::string name) const
{
    Zombie *zombie;

    zombie = new Zombie;
    zombie->set_type(this->type);
    zombie->set_name(name);
    return zombie;
}

std::string get_random_name(void)
{
    std::string name;
    int i(0);

    std::srand(std::time(NULL));
    while (i < 8)
    {
        name.push_back(std::rand() % 96 + 32);
        i++;
    }
    return name;
}

// zombie is not returned. not need to allocate it dynamically
void    ZombieEvent::randomChump(void) const
{
    Zombie zombie;

    zombie.set_name(get_random_name());
    zombie.set_type(this->type);
    zombie.announce();
}