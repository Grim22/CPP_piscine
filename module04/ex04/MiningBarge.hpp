#ifndef MININGBARGE_H
# define MININGBARGE_H

#include <iostream>
#include <string>

class IMiningLaser;
class IAsteroid;

class MiningBarge
{
    private:
        IMiningLaser *lasers[4];
        int num_lasers;

    public:
        MiningBarge(void);
        MiningBarge(const MiningBarge &copy);
        virtual ~MiningBarge(void);
        MiningBarge&  operator=(const MiningBarge &copy);

        void equip(IMiningLaser*);
        void mine(IAsteroid*) const;
};

#endif