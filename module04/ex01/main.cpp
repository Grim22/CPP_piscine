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
    Enemy* c = new SuperMutant;
    Enemy* b = new RadScorpion;
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    
    std::cout << "----" << std::endl;

    // test equip & attack on Radscorpion with PlasmaRifle
    std::cout << *me;
    me->equip(NULL);
    std::cout << *me;
    me->attack(b);
    me->equip(pr);
    std::cout << *me;
    std::cout << *b;
    me->attack(b);
    std::cout << *me;
    std::cout << *b;
    
    std::cout << "----" << std::endl;
    
    // test equip & attack on SuperMutant with PowerFist
    me->equip(pf);
    std::cout << *me;
    std::cout << *c;
    me->attack(c);
    std::cout << *me;
    std::cout << *c;
    me->attack(c);
    me->attack(c);
    me->attack(c);
    me->attack(c);
    me->attack(c);
    std::cout << *me;
    std::cout << *c;
    
    std::cout << "----" << std::endl;

    // test recover 
    me->recoverAP();
    std::cout << *me;
    me->attack(c);
    std::cout << *me;
    me->recoverAP();
    std::cout << *me;
    me->recoverAP();
    std::cout << *me;
    me->recoverAP();
    std::cout << *me;
    me->recoverAP();
    std::cout << *me;
    me->recoverAP();
    std::cout << *me;
    
    std::cout << "----" << std::endl;
    
    delete me;
    delete c;
    delete b;
    delete pr;
    delete pf;
    return 0;
}
