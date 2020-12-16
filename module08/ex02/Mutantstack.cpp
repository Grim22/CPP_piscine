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

Mutantstack::iterator::iterator(): p(NULL)
{
}

Mutantstack::iterator::iterator(int *ptr): p(ptr)
{
}

Mutantstack::iterator::iterator(const iterator &copy): p(copy.p)
{
}

Mutantstack::iterator::~iterator()
{
}

Mutantstack::iterator & Mutantstack::iterator::operator=(const iterator &rhs)
{
    this->p = rhs.p;
    return *this;
}

// Mutantstack::iterator Mutantstack::begin(void)
// {
//     return this->top();
// }

