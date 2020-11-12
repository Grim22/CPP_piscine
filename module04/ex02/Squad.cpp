#include "Squad.hpp"
#include <iostream>

Squad::Squad(void): tab(NULL), count(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Squad::Squad(const Squad &copy)
{
    this->count = copy.count;
    this->tab = new ISpaceMarine*[copy.count];
    for (int i = 0; i < copy.count; i++)
        this->tab[i] = copy.tab[i];
}

Squad::~Squad(void)
{
    // std::cout << "Destructor called" << std::endl;
    for (int i = 0; i < this->count; i++)
        delete this->tab[i];
    delete [] this->tab; 
}

Squad&   Squad::operator=(const Squad &rhs)
{
    // std::cout << "Assignement operator called" << std::endl;

    // Upon assignation, if there was any unit in the Squad before, they must be destroyed before
    // being replaced. You can assume every unit will be created with new
    for (int i = 0; i < this->count; i++)
        delete this->tab[i];
    delete [] this->tab;

    this->count = rhs.count;

    this->tab = new ISpaceMarine*[rhs.count];
    for (int i = 0; i < rhs.count; i++)
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
    for (int i = 0; i < this->count; i++)
    {
        if (elem == this->tab[i])
        {
            std::cout << "Cant add to squad: duplicate" << std::endl;
            return this->count;
        }
    }

    // to add an element to a tab, we need to create a new tab, of size = old_size + 1, then copy old_tab into new tab, then add new element to tab
    ISpaceMarine **new_tab = new ISpaceMarine*[this->count + 1];
    for (int i = 0; i < this->count; i++)
        new_tab[i] = this->tab[i];
    new_tab[this->count] = elem;
    delete [] this->tab;
    this->tab = new_tab;
    this->count++;
    return this->count;
}
    
std::ostream & operator<<(std::ostream &o, const Squad &rhs)
{
    o << "Squad contains" << rhs.getCount() << " units" << std::endl;
    return o;
}
