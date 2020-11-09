#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer(const std::string &name, const std::string &title):
name(name), title(title)
{
    std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Sorcerer::~Sorcerer(void)
{
    std::cout << this->name << ", " << this->title << ", is dead. Consequences will never be the same" << std::endl;
}

Sorcerer&   Sorcerer::operator=(const Sorcerer &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->name = rhs.name;
    this->title = rhs.title;
    return(*this);
}

const std::string & Sorcerer::get_name(void) const
{
    return(this->name);
}

const std::string & Sorcerer::get_title(void) const
{
    return(this->title);
}

void Sorcerer::polymorph(Victim const &target) const
{
    target.getPolymorphed();
}

std::ostream & operator<<(std::ostream &o, const Sorcerer &copy)
{
    o << "I am " << copy.get_name() << ", " << copy.get_title() << ", and I like ponies" << std::endl;
    return o;
}
