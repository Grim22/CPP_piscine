#include "Fixed.hpp"
#include <iostream>
#include <cmath> // roundf

const int Fixed::num_fract_bit = 8;

Fixed::Fixed(void): value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    // std::cout << "Float constructor called" << std::endl;
    this->value = roundf(f * (1 << this->num_fract_bit));
}

Fixed::Fixed(const int i)
{
    // std::cout << "Int constructor called" << std::endl;
    this->value = i << this->num_fract_bit;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    // *this = copy; (egalement possible)
    this->value = copy.getRawBits();
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void    Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float   Fixed::toFloat(void) const
{
    float ret;

    ret = this->value;
    // on converti en float
    ret = ret / (1 << this->num_fract_bit);
    // revient a diviser par 2^num_fract_bit
    return (ret);
}

int     Fixed::toInt(void) const
{
    return (this->value / (1 << this->num_fract_bit));
    // revient a diviser par 2^num_fract_bit
}

Fixed&  Fixed::operator=(const Fixed &rhs)
{
    this->value = rhs.getRawBits();
    return(*this);
}

bool    Fixed::operator>(const Fixed &rhs) const
{
    if (this->getRawBits() > rhs.getRawBits())
        return true;
    else
        return false; 
}

bool    Fixed::operator>=(const Fixed &rhs) const
{
    if (this->getRawBits() >= rhs.getRawBits())
        return true;
    else
        return false; 
}
bool    Fixed::operator<(const Fixed &rhs) const
{
    if (this->getRawBits() < rhs.getRawBits())
        return true;
    else
        return false; 
}
bool    Fixed::operator<=(const Fixed &rhs) const
{
    if (this->getRawBits() <= rhs.getRawBits())
        return true;
    else
        return false; 
}
bool    Fixed::operator==(const Fixed &rhs) const
{
    if (this->getRawBits() == rhs.getRawBits())
        return true;
    else
        return false; 
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
    if (this->getRawBits() != rhs.getRawBits())
        return true;
    else
        return false; 
}

Fixed   Fixed::operator+(const Fixed &rhs) const
{
    Fixed a;
    a.setRawBits(this->getRawBits() + rhs.getRawBits());
    return a;
}

Fixed   Fixed::operator-(const Fixed &rhs) const
{
    Fixed a;
    a.setRawBits(this->getRawBits() - rhs.getRawBits());
    return a;
}

Fixed   Fixed::operator*(const Fixed &rhs) const
{
    // std::cout << "operator * called" << std::endl;
    Fixed a;
    a.setRawBits(this->getRawBits() * rhs.getRawBits());
    a.setRawBits(a.getRawBits() / (1 << this->num_fract_bit));
    // revient a diviser par 2^num_fract_bit
    return a;
}

Fixed   Fixed::operator/(const Fixed &rhs) const
{
    Fixed a;
    a.setRawBits(this->getRawBits() / rhs.getRawBits());
    a.setRawBits(a.getRawBits() * (1 << this->num_fract_bit));
    // revient a multiplier par 2^num_fract_bit
    return a;
}

Fixed&  Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed&  Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed  Fixed::operator++(int)
{
    Fixed copy(*this);
    this->value++;
    return copy;
}

Fixed  Fixed::operator--(int)
{
    Fixed copy(*this);
    this->value--;
    return copy;
}

std::ostream&   operator<<(std::ostream & o, const Fixed &rhs)
{
    o << rhs.toFloat();
    return o;
}

Fixed const&    Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a <= b)
        return a;
    else
        return b; 
}

Fixed&          Fixed::min(Fixed &a, Fixed &b)
{
    if (a <= b)
        return a;
    else
        return b; 
}

Fixed const&    Fixed::max(Fixed const &a, Fixed const &b)       
{
    if (a <= b)
        return b;
    else
        return a; 
}

Fixed&          Fixed::max(Fixed &a, Fixed &b)       
{
    if (a <= b)
        return b;
    else
        return a; 
}

