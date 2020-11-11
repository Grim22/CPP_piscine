#include "Squad.hpp"
#include <iostream>

Squad::Squad(void): tab(NULL), count(0)
{
    // std::cout << "Default constructor called" << std::endl;
}
// Squad::Squad(ISpaceMarine* unit)
// {
//     this->
// }

Squad::Squad(const Squad &copy)
{
    this->count = copy.count;
    this->tab = new ISpaceMarine*[copy.count];
    for (size_t i = 0; i < copy.count; i++)
        this->tab[i] = copy.tab[i];
}

Squad::~Squad(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Squad&   Squad::operator=(const Squad &rhs)
{
    // std::cout << "Assignement operator called" << std::endl;

    // Upon assignation, if there was any unit in the Squad before, they must be destroyed before
    // being replaced. You can assume every unit will be created with new

    for (size_t i = 0; i < this->count; i++)
        delete this->tab[i];
    delete this->tab;
    this->count = rhs.count;
    this->tab = new ISpaceMarine*[rhs.count];
    for (size_t i = 0; i < rhs.count; i++)
        this->tab[i] = rhs.tab[i];
    return(*this);
}

int Squad::getCount() const
{
    return this->count;
}

ISpaceMarine* Squad::getUnit(int N) const
{
    if (N >= this->count || N < 0)
        return NULL;
    return this->tab[N];
}

int Squad::push(ISpaceMarine* elem)
{
    // Adding a null unit, or an unit already in the squad, make no sense at all
    if (elem == NULL)
    {
        std::cout << "Cant add to squad: NULL" << std::endl;
        return this->count;
    }
    int i(0);
    while (i < this->count)
    {
        if (elem == this->tab[i])
        {
            std::cout << "Cant add to squad: duplicate" << std::endl;
            return this->count;
        }
        i++;
    }

    ISpaceMarine **new_tab = new ISpaceMarine*[this->count + 1];
    i = 0;
    while (i < this->count)
    {
        new_tab[i] = this->tab[i];
        i++;
    }
    new_tab[i] = elem;
    delete this->tab;
    this->tab = new_tab;
    this->count++;
    return this->count;
}
    
std::ostream & operator<<(std::ostream &o, const Squad &rhs)
{
    o << "Squad contains" << rhs.getCount() << " units" << std::endl;
    return o;
}
