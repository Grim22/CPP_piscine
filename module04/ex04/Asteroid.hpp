#ifndef ASTEROID_H
# define ASTEROID_H

#include <iostream>
#include <string>

#include "IAsteroid.hpp"

class Asteroid: public IAsteroid
{
    private:
        std::string name;

    public:
        Asteroid(void);
        Asteroid(const Asteroid &copy);
        virtual ~Asteroid(void);
        Asteroid&  operator=(const Asteroid &copy);

        virtual std::string beMined(StripMiner *) const;
        virtual std::string beMined(DeepCoreMiner *) const;
        virtual std::string getName() const;
};

#endif