#ifndef DEEPCOREMINER_H
# define DEEPCOREMINER_H

#include <iostream>
#include <string>

#include "IMiningLaser.hpp"

class DeepCoreMiner: public IMiningLaser
{
    private:

    public:
        DeepCoreMiner(void);
        DeepCoreMiner(const DeepCoreMiner &copy);
        virtual ~DeepCoreMiner(void);
        DeepCoreMiner&  operator=(const DeepCoreMiner &copy);
        
        virtual void mine(IAsteroid*);
};

std::ostream & operator<<(std::ostream &o, const DeepCoreMiner &rhs);

#endif