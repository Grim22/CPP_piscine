#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent(void)
{
    this->type = "not defined";
    std::cout << "event destroyed" << std::endl;
}

ZombieEvent::~ZombieEvent(void)
{
    std::cout << "event destroyed" << std::endl;
}

void    ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
}

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

    srand(time(NULL));
    while (i < 8)
    {
        name.push_back(rand() % 96 + 32);
        i++;
    }
    return name;
}

void    ZombieEvent::randomChump(void) const
{
    Zombie *zombie;
    std::string name;

    zombie = new Zombie;
    zombie->set_name(get_random_name());
    zombie->set_type(this->type);
    zombie->announce();
    delete zombie;
}