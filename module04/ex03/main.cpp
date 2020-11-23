#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    // test copy and assignement of Cure / Ice
    std::cout << "---" << std::endl;
    Cure cure;
    std::cout << cure.getXP() << std::endl;
    cure.use(*bob);
    std::cout << cure.getXP() << std::endl;
    cure.use(*bob);
    std::cout << cure.getXP() << std::endl;
    Cure other_cure(cure);
    std::cout << other_cure.getXP() << std::endl;
    Cure other_other_cure;
    other_other_cure = other_cure;
    std::cout << other_other_cure.getXP() << std::endl;

    // test copy / assignement, equip / unequip of Character
    std::cout << "---" << std::endl;
    Character anton;
    anton.equip(src->createMateria("cure"));
    anton.equip(src->createMateria("ice"));
    Character peter(anton);
    peter.use(0, *bob); // cure
    peter.use(1, *bob); // ice
    peter.use(2, *bob); // nothing equipped at index 2 -> can't use
    peter.unequip(0); // cure unequiped. only one materia left: ice. Index of ice is switched to 0
    // peter.equip(src->createMateria("cure"));
    peter.use(0, *bob); // now ice, as cure was unequiped
    peter.use(1, *bob); // nothing left as ice was moved to index0 -> cant use
    peter.equip(src->createMateria("cure"));
    peter.use(1, *bob); // cure
    peter.use(44, *bob); // invalid index
    anton = peter;
    anton.use(0, *bob);

    delete bob;
    delete me;
    delete src;
}