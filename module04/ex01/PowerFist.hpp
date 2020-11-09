#ifndef PowerFist_H
# define PowerFist_H

#include "AWeapon.hpp"

class PowerFist: public AWeapon
{
    private:

    public:
        PowerFist(void);
        PowerFist(const PowerFist &copy);
        virtual ~PowerFist(void);
        PowerFist&  operator=(const PowerFist &copy);
        virtual void attack() const;
};

#endif