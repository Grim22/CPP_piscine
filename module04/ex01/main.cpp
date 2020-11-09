#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
    PlasmaRifle rif;
    PlasmaRifle rifi;
    rif = rifi;
    PowerFist pow;
    AWeapon *ptr_base = &pow;
    AWeapon *ptr_base1 = &rif;
    ptr_base->attack();
    ptr_base1->attack();
}