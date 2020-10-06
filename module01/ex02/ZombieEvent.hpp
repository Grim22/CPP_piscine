#ifndef ZOMBIEVENT_H
# define ZOMBIEVENT_H

#include <string>

class Zombie;

class ZombieEvent
{
private:
    std::string type;
public:
    void        setZombieType(std::string type);
    Zombie      *newZombie(std::string name) const;
    void        randomChump(void) const;
    ZombieEvent(void);
    ~ZombieEvent(void);
};

#endif