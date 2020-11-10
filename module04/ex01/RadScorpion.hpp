#ifndef RadScorpion_H
# define RadScorpion_H

#include "Enemy.hpp"

class RadScorpion: public Enemy
{
    private:

    public:
        RadScorpion(void);
        RadScorpion(const RadScorpion &copy);
        virtual ~RadScorpion(void);
        RadScorpion&  operator=(const RadScorpion &copy);
};

#endif