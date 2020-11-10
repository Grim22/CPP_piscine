#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"

int main()
{
    // PlasmaRifle rif;
    // PlasmaRifle rifi;
    // rif = rifi;
    // PowerFist pow;
    // AWeapon *ptr_base = &pow;
    // AWeapon *ptr_base1 = &rif;
    // ptr_base->attack();
    // ptr_base1->attack();

    Character* me = new Character("me");
    std::cout << *me;
    // Enemy* b = new RadScorpion();
    Enemy* c = new SuperMutant;
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    me->equip(pr);
    std::cout << *me;
    me->equip(pf);
    me->attack(c);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(c);
    std::cout << *me;
    me->attack(c);
    std::cout << *me;
    return 0;
}
