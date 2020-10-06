#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

# include <string>

class ZombieHorde
{
    Zombie  *horde;
    int     num_zombie;

public:
    ZombieHorde(int N);
    ~ZombieHorde(void);
    void    announce(void) const;
};

#endif