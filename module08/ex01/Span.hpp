#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        Span(void);
        std::vector<int> vec;
        unsigned int capacity;

    public:
        class noSpanException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return "No span to find";
            }
        };
        class spanFullException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Span is already full";
            }
        };
        
        Span(unsigned int N);
        Span(const Span &copy);
        virtual ~Span(void);
        Span&  operator=(const Span &copy);

        void addNumber(int number) throw(spanFullException);
        template <typename T>
        void addRange(typename T::iterator begin, typename T::iterator end)
        {
            typename T::iterator it;
            for (it = begin; it != end; it++)
            {
                this->addNumber(*it);
            }
        }
        int shortestSpan(void) const throw(noSpanException);
        int longestSpan(void) const throw(noSpanException);
        const std::vector<int> &get_vector(void) const;
};

std::ostream & operator<<(std::ostream &o, const Span &rhs);

#endif