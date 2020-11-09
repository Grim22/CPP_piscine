#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

#include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
    private:

    public:
        PlasmaRifle(void);
        PlasmaRifle(const PlasmaRifle &copy);
        virtual ~PlasmaRifle(void);
        PlasmaRifle&  operator=(const PlasmaRifle &copy);
        virtual void attack() const;
};

#endif