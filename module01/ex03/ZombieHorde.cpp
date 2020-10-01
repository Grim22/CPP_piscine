#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string get_random_name(void)
{
    std::string name;
    int i(0);

    while (i < 8)
    {
        name.push_back(std::rand() % 96 + 32);
        i++;
    }
    return name;
}

ZombieHorde::ZombieHorde(int N)
{
    int i(0);
    this->horde = new Zombie[N];
    this->num_zombie = N;
    std::srand(std::time(NULL));
    while (i < N)
    {
        this->horde[i].set_name(get_random_name());
        i++;
    }
}

ZombieHorde::~ZombieHorde(void)
{
    delete[] this->horde;
}

void    ZombieHorde::announce(void) const
{
    int i(0);

    while (i < this->num_zombie)
    {
        this->horde[i].announce();
        i++;
    }
}

Zombie  *ZombieHorde::getHorde(void) const
{
    return (this->horde);
}
