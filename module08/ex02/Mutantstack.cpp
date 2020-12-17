#include "Mutantstack.hpp"
#include <iostream>

Mutantstack::Mutantstack(const std::deque<int> &ctnr): 
std::stack<int>(ctnr)
{    
}

Mutantstack::Mutantstack(const Mutantstack &copy): 
std::stack<int>(copy)
{
}

Mutantstack::~Mutantstack(void)
{
}

Mutantstack&   Mutantstack::operator=(const Mutantstack &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->stack<int>::operator=(rhs);
    return(*this);
}

Mutantstack::iterator Mutantstack::end(void)
{
    return Mutantstack::iterator(this->c.end());
}

Mutantstack::iterator Mutantstack::begin(void)
{
    return Mutantstack::iterator(this->c.begin());
}

Mutantstack::iterator::iterator()
{
}

Mutantstack::iterator::iterator(std::deque<int>::iterator it): it(it)
{
}

Mutantstack::iterator::iterator(const iterator &copy): it(copy.it)
{
}

Mutantstack::iterator::~iterator()
{
}

Mutantstack::iterator & Mutantstack::iterator::operator=(const iterator &rhs)
{
    this->it = rhs.it;
    return *this;
}

int & Mutantstack::iterator::operator*() const
{
    return *this->it;
}

Mutantstack::iterator& Mutantstack::iterator::operator++()
{
    this->it++;
    return *this;
}

Mutantstack::iterator Mutantstack::iterator::operator++(int)
{
    Mutantstack::iterator tmp(*this);
    this->it++;
    return tmp;
}

Mutantstack::iterator& Mutantstack::iterator::operator--()
{
    this->it--;
    return *this;
}

Mutantstack::iterator Mutantstack::iterator::operator--(int)
{
    Mutantstack::iterator tmp(*this);
    this->it--;
    return tmp;
}

bool Mutantstack::iterator::operator==(const iterator &rhs) const
{
    if (this->it == rhs.it)
        return true;
    else
        return false;
}

bool Mutantstack::iterator::operator!=(const iterator &rhs) const
{
    if (this->it != rhs.it)
        return true;
    else
        return false;
}

