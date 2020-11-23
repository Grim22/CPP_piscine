#include "Character.hpp"
#include <iostream>

Character::Character(void): name(""), ap_num(0), weapon(NULL)
{
    // std::cout << "Default constructor called" << std::endl;
}

Character::Character(std::string const & name): name(name), ap_num(40), weapon(NULL)
{
    // std::cout << "Default constructor called" << std::endl;
}

Character::Character(const Character &copy):
name(copy.name), ap_num(copy.ap_num), weapon(copy.weapon)
{
    // std::cout << "Copy constructor called" << std::endl;
}

const AWeapon * Character::getWeapon() const
{
    return this->weapon;
}

const std::string & Character::getName() const
{
    return this->name;
}

int Character::getAp() const
{
    return this->ap_num;
}

Character::~Character(void)
{
    // std::cout << "Destructor called" << std::endl;
}

void Character::recoverAP()
{
    if (this->ap_num >= 30)
        this->ap_num = 40;
    else
        this->ap_num += 10;
    std::cout << "AP recovered" << std::endl;
}

void Character::equip(AWeapon* weapon)
{
    this->weapon = weapon;
    if (weapon)
        std::cout << weapon->getName() << " equiped" << std::endl;
}

void Character::attack(Enemy* enemy)
{
    if (this->weapon == NULL)
    {
        std::cout << "No weapon !" << std::endl;
        return;
    }
    if (this->ap_num < this->weapon->getAPCost())
    {
        std::cout << "Not enough AP to attack !" << this->ap_num << " vs " << this->weapon->getAPCost() << std::endl;
        
        return;
    }
    std::cout << this->name << " attacks " << enemy->gettype() << " with a " << this->weapon->getName() << std::endl;
    this->weapon->attack();
    this->ap_num -= this->weapon->getAPCost();
    enemy->takeDamage(this->weapon->getDammage());
    if (enemy->getHP() <= 0)
        delete enemy;
}

Character&   Character::operator=(const Character &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->name = rhs.name;
    this->ap_num = rhs.ap_num;
    this->weapon = rhs.weapon;
    return(*this);
}

std::ostream & operator<<(std::ostream &o, const Character &rhs)
{
    if (rhs.getWeapon())
        o << rhs.getName() << " has " << rhs.getAp() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    else
        o << rhs.getName() << " has " << rhs.getAp() << " and is unarmed" << std::endl;
    return o;
}
