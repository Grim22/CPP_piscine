#include "A.hpp"
#include "C.hpp"
#include "B.hpp"
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time

Base *generate(void)
{
    if (rand() % 3 == 0)
    {
        std::cout << "A generated" << std::endl;
        return new A;
    }
    else if (rand() % 3 == 1)
    {
        std::cout << "B generated" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "C generated" << std::endl;
        return new C;
    }
}

void identify_from_reference( Base & p)
{
    try
    {
        A & ref_A = dynamic_cast<A&>(p);
        (void)ref_A;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        B & ref_B = dynamic_cast<B&>(p);
        (void)ref_B;
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        C & ref_C = dynamic_cast<C&>(p);
        (void)ref_C;
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }    
}

void identify_from_pointer(Base * p)
{
    A * ptr_A;
    B * ptr_B;
    C * ptr_C;
    ptr_A = dynamic_cast<A*>(p);
    ptr_B = dynamic_cast<B*>(p);
    ptr_C = dynamic_cast<C*>(p);
    if (ptr_A)
        std::cout << "A" << std::endl;
    if (ptr_B)
        std::cout << "B" << std::endl;
    if (ptr_C)
        std::cout << "C" << std::endl;
}


int main()
{
    Base *ptr;
    std::srand(time(NULL));
    ptr = generate();
    identify_from_pointer(ptr);
    identify_from_reference(*ptr);
    delete ptr;
}