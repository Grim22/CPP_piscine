#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream> //std::ofstream
#include <sstream> //std::sstream

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
Form("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
Form(copy)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    //std::cout << "SC Destructor called" << std::endl;
}

PresidentialPardonForm&   PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->Form::operator=(rhs);
    return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const throw(std::ios_base::failure, GradeTooLowException, NotSignedException)
{
    this->Form::execute(executor); // throws exceptions
    
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}