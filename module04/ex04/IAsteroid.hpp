#ifndef IASTEROID_H
# define IASTEROID_H

#include <iostream>
#include <string>

class StripMiner;
class DeepCoreMiner;

class IAsteroid
{
    private:

    public:
        virtual ~IAsteroid() {}
        virtual std::string beMined(StripMiner *) const = 0;
        virtual std::string beMined(DeepCoreMiner *) const = 0;
        virtual std::string getName() const = 0;
};

#endif