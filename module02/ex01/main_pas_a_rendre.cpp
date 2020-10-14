#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( 10 ); Fixed const c( 42.42f ); Fixed const d( b );
    a = Fixed( 1234.4321f ); // float constructor called THEN assignement operator called THEN destructor called
    // how does the programm knows it can call the destructor ?
        //  When is destructor called?
        // A destructor function is called automatically when the object goes out of scope:
        // (1) the function ends
        // (2) the program ends
        // (3) a block containing local variables ends --> is that it ?
        // (4) a delete operator is called 
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}