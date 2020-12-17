#include <iostream>

template <typename T>
MutantStack<T>::MutantStack(const std::deque<T> &ctnr): 
std::stack<T>(ctnr)
{    
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy): 
std::stack<T>(copy)
{
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
MutantStack<T>&   MutantStack<T>::operator=(const MutantStack &rhs)
{
    this->stack::operator=(rhs);
    return(*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return MutantStack::iterator(this->c.end());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return MutantStack::iterator(this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
    return MutantStack::const_iterator(this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
    return MutantStack::const_iterator(this->c.begin());
}
