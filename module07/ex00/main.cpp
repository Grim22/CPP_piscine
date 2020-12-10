#include "templates.hpp"
#include "iostream"
#include "Fixed.hpp"

// int main()
// {
//     int a = 32;
//     int b = 42;
//     std::cout << max<int>(a, b) << std::endl;
//     std::cout << min<int>(a, b) << std::endl;
//     swap<int>(a, b);
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b ); // implicit synthax (:: before function means that the resolution should occur from the global namespace)
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d); // implicit synthax
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

Fixed e(42.42f);
Fixed f(23);
swap<Fixed>(e, f); // explicit synthax
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
return 0;
}