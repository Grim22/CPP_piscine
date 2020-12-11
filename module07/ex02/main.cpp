#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> a(5);
    std::cout << a.size() << std::endl;
    a[0] = 10;
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
    try
    {
        a[6] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}