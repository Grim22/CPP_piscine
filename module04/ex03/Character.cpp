#include "Character.hpp"
#include <iostream>

Character::Character(void):
inventory(), materia_num(0), name("unset") // "In order to set an array of pointers to nulls in constructor initializer list, you can use the () initializer"
{
    std::cout << "Default constructor called" << std::endl;
}

Character::Character(const std::string & name):
inventory(), materia_num(0), name(name) // "In order to set an array of pointers to nulls in constructor initializer list, you can use the () initializer"
{
    std::cout << "Param constructor called" << std::endl;
}

Character::Character(const Character &copy):
materia_num(copy.materia_num), name(copy.name)
{
    std::cout << "Copy constructor called" << std::endl;
    for (int i = 0; i < copy.materia_num; i++)
        this->inventory[i] = copy.inventory[i]->clone();
}

Character::~Character(void)
{
    std::cout << "Destructor called" << std::endl;
    for (int i = 0; i < this->materia_num; i++)
    {
        delete this->inventory[i];
        this->inventory[i] = NULL;
    }
}

Character&   Character::operator=(const Character &rhs)
{
    // Assignation of a Character must be deep, of course. The old Materia of a Character must be deleted.
    std::cout << "Assignement operator called" << std::endl;
    for (int i = 0; i < this->materia_num; i++)
    {
        delete this->inventory[i];
        this->inventory[i] = NULL;
    }

    for (int i = 0; i < rhs.materia_num ; i++)
        this->inventory[i]  = rhs.inventory[i];
    this->materia_num = rhs.materia_num;
    this->name = rhs.name;
    
    return(*this);
}

// std::ostream & operator<<(std::ostream &o, const Character &rhs)
// {
//     o << /*text*/ << std::endl;
//     return o;
// }

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
// He’ll equip the Materia in slots 0 to 3, in this order.

// In case we try to equip a Materia in a full inventory, or use/uneqip a nonexistent
// Materia, don’t do a thing.
    if (m == NULL || this->materia_num == 4)
        return;
    this->inventory[materia_num] = m; // we the pointer given as argument (instead of a new pointer with clone). else we should have deleted the pointer given as argument (which is not the case for tmp in main)
    this->materia_num++;
}

void Character::unequip(int idx)
{
    // The unequip method must NOT delete Materia!
    if (idx >= this->materia_num || idx < 0)
        return;
    delete this->inventory[idx]; // frees the pointer to materia, does not delete the object itself
    this->inventory[idx] = NULL;
    this->materia_num--;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= this->materia_num || idx < 0)
    {
        std::cout << "cant perform use" << std::endl;
        return;
    }
    this->inventory[idx]->use(target);
}