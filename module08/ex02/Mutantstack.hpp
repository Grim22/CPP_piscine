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
                int *p;
            public:
                iterator();
                iterator(int *p);
                iterator(const iterator &copy);
                ~iterator();
                iterator& operator=(const iterator &rhs);
        };
        
        std::deque<int>::iterator begin(void) 
        {
            return this->c.begin();
        };
        std::deque<int>::iterator end(void)
        {
            return this->c.end();
        };
};

#endif