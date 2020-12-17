#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <iostream>
#include <string>
#include <stack>
#include <iterator>
#include <deque>

class Mutantstack: public std::stack<int>
{
    private:
        
    public:
        Mutantstack(const std::deque<int> &ctnr = std::deque<int>()); // acts as a default constructor (default value is specified) -> Ok Coplien
        Mutantstack(const Mutantstack &copy);
        virtual ~Mutantstack(void);
        Mutantstack&  operator=(const Mutantstack &copy);

        class iterator: public std::iterator<std::bidirectional_iterator_tag, int>
        {
            private:
                std::deque<int>::iterator it;
            public:
                iterator();
                iterator(std::deque<int>::iterator it);
                iterator(const iterator &copy);
                ~iterator();
                iterator& operator=(const iterator &rhs);
                int & operator*() const;
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

#endif