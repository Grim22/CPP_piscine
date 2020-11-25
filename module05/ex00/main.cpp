#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat alain("alain", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-----" << std::endl;
    
    try
    {
        Bureaucrat alain("alain", 200);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-----" << std::endl;
    
    try
    {
        Bureaucrat alain("alain", 2);
        std::cout << alain;
        alain.incGrade();
        std::cout << alain;
        alain.incGrade();
        std::cout << alain;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-----" << std::endl;
    
    try
    {
        Bureaucrat alain("alain", 149);
        std::cout << alain;
        alain.decGrade();
        std::cout << alain;
        alain.decGrade();
        std::cout << alain;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}