#include "Array.hpp"
#include "Fixed.hpp"
#include <iostream>

int main()
{
    // Array<int>
    Array<int>e; // empty array
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
    // allocation
    Array<int>b(6);
    b[3] = 42;
    a = b;
    std::cout << a[3] << std::endl;
    // copy construction
    const Array<int>c(b);
    std::cout << c[3] << std::endl;
    
    std::cout << "---" << std::endl;

    // Array<Fixed>
    Array<Fixed> E;
    Array<Fixed> A(5);
    std::cout << A.size() << std::endl;
    A[0] = 10;
    std::cout << A[0] << std::endl;
    std::cout << A[1] << std::endl;
    try
    {
        A[6] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // allocation
    Array<Fixed>B(6);
    B[3] = 42.42f;
    A = B;
    std::cout << A[3] << std::endl;
    // copy construction
    Array<Fixed>C(B);
    std::cout << C[3] << std::endl;

    
}