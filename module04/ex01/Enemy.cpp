#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(void): hp(0), type("")
{}

Enemy::Enemy(int hp, std::string const & type):
hp(hp), type(type)
{}

Enemy::Enemy(const Enemy &copy):
hp(copy.hp), type(copy.type)
{
    std::cout << "Copy constructor called" << std::endl;
}

Enemy::~Enemy(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Enemy::getHP() const
{
    return this->hp;
}

const std::string & Enemy::gettype() const
{
    return this->type;
}

void Enemy::takeDamage(int damage)
{
    int taken(damage);
    if (damage < 0)
        taken = 0;
    if (this->hp < damage)
        taken = this->hp;
    this->hp -= taken;
    if (this->hp == 0)
        std::cout << this->type << "is dead !" << std::endl;
    else
        std::cout << this->type << " has " << this->hp << " HP remaining" << std::endl;
}
Enemy&   Enemy::operator=(const Enemy &rhs)
{
    std::cout << "E Assignement operator called" << std::endl;
    this->hp = rhs.hp;
    this->type = rhs.type;
    return(*this);
}
