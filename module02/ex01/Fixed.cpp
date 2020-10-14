#include "Fixed.hpp"
#include <iostream>
#include <cmath> // roundf

const int Fixed::num_fract_bit = 3;

Fixed::Fixed(void): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    float tmp;
    int i;
    std::cout << "Float constructor called" << std::endl;
    i = 0;
    tmp = f;
    while(i < this->num_fract_bit)
    {
        tmp = tmp * 2;
        i++;
    }
    this->value = roundf(tmp);
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = i << this->num_fract_bit;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    // *this = copy; (egalement possible)
    this->value = copy.getRawBits();
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float   Fixed::toFloat(void) const
{
    float ret;
    int i;

    ret = this->value;
    i = 0;
    while (i < this->num_fract_bit)
    {
        ret = ret / 2;
        i++;
    }
    return (ret);
}

int     Fixed::toInt(void) const
{
    return (this->value >> this->num_fract_bit);
}

Fixed&  Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->value = rhs.getRawBits();
    return(*this);
}

std::ostream &  operator<<(std::ostream & o, const Fixed &rhs)
{
    o << rhs.toFloat();
    return o;
}

