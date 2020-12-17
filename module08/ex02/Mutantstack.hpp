#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <iostream>
#include <string>
#include <stack>
#include <iterator>
#include <deque>

template <typename T>
class Mutantstack: public std::stack<T>
{
    private:
        
    public:
        Mutantstack(const std::deque<T> &ctnr = std::deque<T>()); // acts as a default constructor (default value is specified) -> Ok Coplien
        Mutantstack(const Mutantstack &copy);
        virtual ~Mutantstack(void);
        Mutantstack&  operator=(const Mutantstack &copy);

        class iterator: public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                typename std::deque<T>::iterator it;
            public:
                iterator();
                iterator(typename std::deque<T>::iterator it);
                iterator(const iterator &copy);
                ~iterator();
                iterator& operator=(const iterator &rhs);
                T & operator*() const;
                iterator& operator++(); // preincrement (++a)
                iterator operator++(int); // postincrement (a++)
                iterator& operator--();
                iterator operator--(int);
                bool operator==(const iterator &rhs) const;
                bool operator!=(const iterator &rhs) const;
        };
        
        iterator begin(void);
        iterator end(void);
};

#include "Mutantstack.ipp"

#endif