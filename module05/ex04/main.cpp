#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <fstream>

int main()
{
    Intern Xavier;
    Bureaucrat Michel("mich", 1);
    Bureaucrat Antoine("tonio", 1);
    Bureaucrat Newbie("newbie", 150);
    try
    {
        OfficeBlock block(&Xavier, &Michel, &Antoine);
        
        block.doBureaucracy("robotomy request", "people");
        std::cout << "-----" << std::endl;
        
        block.doBureaucracy("presidential pardon", "people");
        std::cout << "-----" << std::endl;
        
        // Intern: Form Type Not Found Exception
        block.doBureaucracy("random", "people");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-----" << std::endl;

    try
    {
        // OfficeBlock: NULL pointer exception
        OfficeBlock block2;
        block2.doBureaucracy("presidential pardon", "people");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        // create empty block and add interns and bureaucrats to it
        OfficeBlock block2;
        block2.addIntern(&Xavier);
        block2.addSignB(&Michel);
        block2.addExec(&Michel);
        block2.doBureaucracy("shruberry creation", "people");
        std::cout << "-----" << std::endl;

        // OfficeBlock NULL pointer exception
        block2.addSignB(NULL);
        block2.doBureaucracy("shruberry creation", "people");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        // Bureaucrat: grade too low exception
        OfficeBlock block2;
        block2.addIntern(&Xavier);
        block2.addSignB(&Newbie);
        block2.addExec(&Michel);
        block2.doBureaucracy("shruberry creation", "people");
        std::cout << "-----" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    
    std::cout << "-----" << std::endl;
}