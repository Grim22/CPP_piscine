#ifndef StripMiner_H
# define StripMiner_H

#include <iostream>
#include <string>

#include "IMiningLaser.hpp"

class StripMiner: public IMiningLaser
{
    private:

    public:
        StripMiner(void);
        StripMiner(const StripMiner &copy);
        virtual ~StripMiner(void);
        StripMiner&  operator=(const StripMiner &copy);
        
        virtual void mine(IAsteroid*);
};

std::ostream & operator<<(std::ostream &o, const StripMiner &rhs);

#endif