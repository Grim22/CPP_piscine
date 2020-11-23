#ifndef IMININGLASER_H
# define IMININGLASER_H

#include <iostream>
#include <string>

class IAsteroid;

class IMiningLaser
{
    private:

    public:
        virtual ~IMiningLaser() {}
        virtual void mine(IAsteroid*) = 0;
};

#endif