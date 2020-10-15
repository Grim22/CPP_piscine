#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a(2);
    Fixed b(2.1f);
    Fixed e(a / b); 
    std::cout << "e is " << e << std::endl;
    std::cout << "e is " << e.toInt() << " as integer" << std::endl;
    if (a != b)
        std::cout << "a is greater than b" << std::endl;
    return 0;

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