#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H

#include "Enemy.hpp"

class SuperMutant: Enemy
{
    private:

    public:
        SuperMutant(void);
        SuperMutant(const SuperMutant &copy);
        virtual ~SuperMutant(void);
        SuperMutant&  operator=(const SuperMutant &copy);
        virtual void takeDamage(int);
};

#endif