#ifndef AWEAPON_H
# define AWEAPON_H

#include <string>

class AWeapon{
    private:
        std::string name;
        int damage;
        int apcost;

    public:
        AWeapon(void);
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(const AWeapon &copy);
        AWeapon&  operator=(const AWeapon &copy);
        virtual ~AWeapon(void);
        int getAPCost() const;
        int getDammage() const;
        std::string const getName() const;
        virtual void attack() const = 0;
};

#endif