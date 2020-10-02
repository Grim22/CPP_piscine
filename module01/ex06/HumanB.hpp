
# ifndef HUMAN_B_H
#define HUMAN_B_H

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon*     weapon; // on utilise un pointeur ici, car on souhaite pouvoir initialiser weapon apres la creation de l'objet Human (pas possible avec la reference)
public:
    HumanB      (std::string name);
    ~HumanB     (void);
    void        setWeapon(Weapon &weapon);
    void        attack(void) const;
};

# endif