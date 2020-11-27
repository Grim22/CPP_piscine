#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

int main()
{
    try
    {
        Bureaucrat Mike("mike", 135);
        ShruberryCreationForm s_form("big_man");
        //std::cout << s_form;
        Mike.executeForm(s_form); // can't because not signed
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;
    
    try
    {
        Bureaucrat Mike("mike", 140);
        ShruberryCreationForm s_form("big_man");
        //std::cout << s_form;
        Mike.signForm(s_form);
        Mike.executeForm(s_form); // can't because grade to low
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;
    
    try
    {
        Bureaucrat Mike("mike", 1);
        ShruberryCreationForm s_form("big_man");
        PresidentialPardonForm p_form("Trump");
        std::cout << p_form;
        RobotomyRequestForm r_form("suzan");
        std::cout << r_form;
        std::cout << "-----" << std::endl;
        Mike.signForm(s_form);
        Mike.executeForm(s_form);
        std::cout << "-----" << std::endl;
        Mike.signForm(p_form);
        Mike.executeForm(p_form);
        std::cout << "-----" << std::endl;
        Mike.signForm(r_form);
        Mike.executeForm(r_form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;
}