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
    if (this->vec.size() <= 1)
        throw noSpanException();
    int min = std::abs(this->vec[1] - this->vec[0]);
    std::vector<int>::const_iterator it;
    for (it = this->vec.begin(); it + 1 < this->vec.end(); it++)
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
