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
Mutantstack<T>::iterator::iterator()
{
}

template <typename T>
Mutantstack<T>::iterator::iterator(typename std::deque<T>::iterator it): it(it)
{
}

template <typename T>
Mutantstack<T>::iterator::iterator(const iterator &copy): it(copy.it)
{
}

template <typename T>
Mutantstack<T>::iterator::~iterator()
{
}

template <typename T>
typename Mutantstack<T>::iterator & Mutantstack<T>::iterator::operator=(const iterator &rhs)
{
    this->it = rhs.it;
    return *this;
}

template <typename T>
T & Mutantstack<T>::iterator::operator*() const
{
    return *this->it;
}

template <typename T>
typename Mutantstack<T>::iterator& Mutantstack<T>::iterator::operator++()
{
    this->it++;
    return *this;
}

template <typename T>
typename Mutantstack<T>::iterator Mutantstack<T>::iterator::operator++(int)
{
    Mutantstack::iterator tmp(*this);
    this->it++;
    return tmp;
}

template <typename T>
typename Mutantstack<T>::iterator& Mutantstack<T>::iterator::operator--()
{
    this->it--;
    return *this;
}

template <typename T>
typename Mutantstack<T>::iterator Mutantstack<T>::iterator::operator--(int)
{
    Mutantstack::iterator tmp(*this);
    this->it--;
    return tmp;
}

template <typename T>
bool Mutantstack<T>::iterator::operator==(const iterator &rhs) const
{
    if (this->it == rhs.it)
        return true;
    else
        return false;
}

template <typename T>
bool Mutantstack<T>::iterator::operator!=(const iterator &rhs) const
{
    if (this->it != rhs.it)
        return true;
    else
        return false;
}

