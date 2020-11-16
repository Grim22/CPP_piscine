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
        this->tab[i] = copy.tab[i]->clone();
}

Squad::~Squad(void)
{
    // std::cout << "Destructor called" << std::endl;
    for (int i = 0; i < this->count; i++)
    {
        delete this->tab[i];
        this->tab[i] = NULL;
    }
    delete [] this->tab;
    // std::cout << "Squad deleted" << std::endl;
}

Squad&   Squad::operator=(const Squad &rhs)
{
    // std::cout << "Squad Assignement operator called" << std::endl;

    // Upon assignation, if there was any unit in the Squad before, they must be destroyed before
    // being replaced. You can assume every unit will be created with new
    for (int i = 0; i < this->count; i++)
    {
        delete this->tab[i];
        this->tab[i] = NULL;
    }
    delete [] this->tab;

    this->count = rhs.count;
    
    // Upon copy construction or assignation of a Squad, the copy must be deep
    // we allocate a new pointer this->tab[], then copy the content pointed
    if (rhs.count)
        this->tab = new ISpaceMarine*[rhs.count];
    for (int i = 0; i < rhs.count; i++)
    {
        // we need to make a deep copy on the content pointed:
        // "this->tab[i] = rhs.tab[i]" would result in both squads pointing to the same units: when one squad is deleted, its unit are deleted too, so the copy of the squad gets impacted
        this->tab[i] = rhs.tab[i]->clone();
    }

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
    new_tab[this->count] = elem; // we use the pointer given as argument (not a copy with elem.clone()): else we should have deleted the pointer after sending it to the function, which is not the case in main (bob and jim are not deleted)
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
