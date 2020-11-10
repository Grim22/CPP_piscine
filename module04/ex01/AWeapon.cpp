#include "AWeapon.hpp"
#include <iostream>

AWeapon::AWeapon(std::string const & name, int apcost, int damage):
name(name), damage(damage), apcost(apcost)
{
    std::cout << "AWeapon called" << std::endl;
}
AWeapon::AWeapon(void):
name(""), damage(0), apcost(0){}

AWeapon::AWeapon(const AWeapon &copy):
name(copy.name), damage(copy.damage), apcost(copy.apcost)
{
    std::cout << "Copy constructor called" << std::endl;
}

AWeapon::~AWeapon(void)
{
    std::cout << "AWeapon Destructor called" << std::endl;
}

AWeapon&   AWeapon::operator=(const AWeapon &rhs)
{
    std::cout << "AWeapon Assignement operator called" << std::endl;
    this->name = rhs.name;
    this->damage = rhs.damage;
    this->apcost = rhs.apcost;
    return(*this);
}

int AWeapon::getAPCost() const
{
    return this->apcost;
}

int AWeapon::getDammage() const
{
    return this->damage;
}

std::string const AWeapon::getName() const
{
    return this->name;
}
