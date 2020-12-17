#include "Mutantstack.hpp"
#include <iostream>

template <typename T>
Mutantstack<T>::Mutantstack(const std::deque<T> &ctnr): 
std::stack<T>(ctnr)
{    
}

template <typename T>
Mutantstack<T>::Mutantstack(const Mutantstack &copy): 
std::stack<T>(copy)
{
}

template <typename T>
Mutantstack<T>::~Mutantstack(void)
{
}

template <typename T>
Mutantstack<T>&   Mutantstack<T>::operator=(const Mutantstack &rhs)
{
    this->stack::operator=(rhs);
    return(*this);
}

template <typename T>
typename Mutantstack<T>::iterator Mutantstack<T>::end(void)
{
    return Mutantstack::iterator(this->c.end());
}

template <typename T>
typename Mutantstack<T>::iterator Mutantstack<T>::begin(void)
{
    return Mutantstack::iterator(this->c.begin());
}

template <typename T>
typename Mutantstack<T>::const_iterator Mutantstack<T>::end(void) const
{
    return Mutantstack::const_iterator(this->c.end());
}

template <typename T>
typename Mutantstack<T>::const_iterator Mutantstack<T>::begin(void) const
{
    return Mutantstack::const_iterator(this->c.begin());
}
