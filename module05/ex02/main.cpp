#include "ShruberryCreationForm.hpp"
#include "Bureaucrat.hpp"

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
        Bureaucrat Mike("mike", 135);
        ShruberryCreationForm s_form("big_man");
        Mike.signForm(s_form);
        Mike.executeForm(s_form); // can't because grade to low
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;
}