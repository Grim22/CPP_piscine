#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
    private:
        std::string name;
        int ap_num;
        AWeapon * weapon;
    public:
        Character(void);
        Character(std::string const & name);
        Character(const Character &copy);
        ~Character(void);
        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        const std::string & getName() const;
        const AWeapon * getWeapon() const;
        int getAp() const;
        Character&  operator=(const Character &copy);
};

std::ostream & operator<<(std::ostream &o, const Character &rhs);

#endif