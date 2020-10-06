#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// srand() and rand()
// rand() generates random numbers. Muliple calls to rand() inside the programm will generate a sequence of random numbers
// if srand() is not set, or set to a fixed value, rand() will generate the same random number(s) each time the programm is run
// we set srand() to a different value each time, so that rand() will generate different random number(s)

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
    if (N < 0)
    {
        std::cout << "Num of zombie must be positive" << std::endl;
        this->num_zombie = N;
        return ;
    }
    this->horde = new Zombie[N];
    this->num_zombie = N;
    std::srand(std::time(NULL));
    int i(0);
    while (i < N)
    {
        this->horde[i].set_name(get_random_name());
        i++;
    }
}

ZombieHorde::~ZombieHorde(void)
{
    if (this->num_zombie > 0)
        delete[] this->horde;
}

void    ZombieHorde::announce(void) const
{
    int i(0);

    if (this->num_zombie < 0)
        return ;
    while (i < this->num_zombie)
    {
        this->horde[i].announce();
        i++;
    }
}
