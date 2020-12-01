#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <fstream>

int main()
{
    Intern Xavier;
    Bureaucrat Michel("mich", 1);
    Form *form;
    try
    {
        form = Xavier.makeForm("robotomy request", "mike");
        std::cout << *form;
        delete form;
        std::cout << "-----" << std::endl;
        
        form = Xavier.makeForm("presidential pardon", "mike");
        std::cout << *form;
        delete form;
        std::cout << "-----" << std::endl;
        
        form = Xavier.makeForm("shruberry creation", "mike");
        std::cout << *form;
        Michel.signForm(*form);
        Michel.executeForm(*form);
        delete form;
        std::cout << "-----" << std::endl;

        form = Xavier.makeForm("random", "mike");
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-----" << std::endl;
}