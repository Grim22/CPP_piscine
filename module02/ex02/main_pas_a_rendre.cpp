#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
    // Fixed a(10);
    // Fixed b(2.1f);
    // Fixed e(a--); 
    // std::cout << "e is " << e << std::endl;
    // std::cout << "e is " << e.toInt() << " as integer" << std::endl;
    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // Fixed f (Fixed::max(a, b));
    // std::cout << "max of a and b is " << f << std::endl;
    // f = Fixed::min(a, b);
    // std::cout << "min of a and b is " << f << std::endl;
    // Fixed &g = Fixed::max(a, b);
    // g.setRawBits(256);
    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;

    // return 0;

    // Fixed a;
    // Fixed const b( 10 ); Fixed const c( 42.42f ); Fixed const d( b );
    // a = Fixed( 1234.4321f ); // float constructor called THEN assignement operator called THEN destructor called
    //     // float constructor -> temporary object is created and sent to the assignement operator.  
    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;
    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    // return 0;
}