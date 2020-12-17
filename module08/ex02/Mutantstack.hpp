#ifndef MutantStack_H
# define MutantStack_H

#include <iostream>
#include <string>
#include <stack>
#include <iterator>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
    private:
        
    public:
        MutantStack(const std::deque<T> &ctnr = std::deque<T>()); // acts as a default constructor (default value is specified) -> Ok Coplien
        MutantStack(const MutantStack &copy);
        virtual ~MutantStack(void);
        MutantStack&  operator=(const MutantStack &copy);

        typedef typename std::deque<T>::iterator iterator; // we define a "member type" (or "nested type"): the class name acts like a namespace for the nested type: MutantStack::iterator
        typedef typename std::deque<T>::const_iterator const_iterator;

        iterator begin(void); // typename std::deque<T>::iterator begin(void) is equivalent
        iterator end(void); // typename std::deque<T>::iterator end(void) is equivalent

        const_iterator begin(void) const; // this overload will be used by const MutantStack object (const_iterator is returned, which means that *const_it can not be modified)
        const_iterator end(void) const;

};

#include "Mutantstack.ipp"

#endif