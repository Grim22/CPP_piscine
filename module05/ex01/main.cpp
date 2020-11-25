#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form A("A-form", 0, 2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;

    try
    {
        Form B("B", 50, 40);
        Bureaucrat Al("Albert", 68);
        std::cout << B;
        Al.signForm(B); // can't sign
        std::cout << B;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-----" << std::endl;
    
    try
    {
        Form B("B", 50, 40);
        Bureaucrat Al("Albert", 48);
        std::cout << B;
        Al.signForm(B); // can sign
        std::cout << B;
        Al.signForm(B);
        std::cout << B;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}