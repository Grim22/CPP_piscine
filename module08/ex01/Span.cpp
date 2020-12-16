#include "Span.hpp"
#include <iostream>
#include <cstdlib>

Span::Span(unsigned int N): capacity(N)
{
}

Span::Span(const Span &copy): vec(copy.vec) ,capacity(copy.capacity)
{

}

Span::~Span(void)
{
}

Span&   Span::operator=(const Span &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->vec = rhs.vec;
    this->capacity = rhs.capacity;
    return(*this);
}

const std::vector<int> &Span::get_vector(void) const
{
    return this->vec;
}

std::ostream & operator<<(std::ostream &o, const Span &rhs)
{
    std::vector<int>::const_iterator it;
    for (it = rhs.get_vector().begin() ; it < rhs.get_vector().end() ; it++)
        o << *it << " ";
    o << std::endl;
    return o;
}

void Span::addNumber(int number) throw(spanFullException)
{
    if (this->vec.size() == this->capacity)
        throw spanFullException();
    this->vec.push_back(number);
}

int Span::shortestSpan(void) const throw(noSpanException)
{
    // sort (copy of) vector, then find min of abs(vec[i] - vec[i + 1])
    if (this->vec.size() <= 1)
        throw noSpanException();

    std::vector<int> tmp(this->vec);
    std::sort(tmp.begin(), tmp.end());
    int min(std::abs(tmp[1] - tmp[0]));
    for (std::vector<int>::const_iterator it = tmp.begin() + 1; it + 1 < tmp.end(); it++)
    {
        if (std::abs(*it - *(it + 1)) < min)
            min = std::abs(*it - *(it + 1));
    }
    return min;
}

int Span::longestSpan(void) const throw(noSpanException)
{
    if (this->vec.size() <= 1)
        throw noSpanException();
    return std::abs(*std::min_element(this->vec.begin(), this->vec.end()) - *std::max_element(this->vec.begin(), this->vec.end()));
}
