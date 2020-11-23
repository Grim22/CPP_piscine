#ifndef Comet_H
# define Comet_H

#include <iostream>
#include <string>

#include "IAsteroid.hpp"

class Comet: public IAsteroid
{
    private:
        std::string name;

    public:
        Comet(void);
        Comet(const Comet &copy);
        virtual ~Comet(void);
        Comet&  operator=(const Comet &copy);

        virtual std::string beMined(StripMiner *) const;
        virtual std::string beMined(DeepCoreMiner *) const;
        virtual std::string getName() const;
};

#endif