#include "ShruberryCreationForm.hpp"
#include <iostream>
#include <fstream> //std::ofstream
#include <sstream> //std::sstream

ShruberryCreationForm::ShruberryCreationForm(const std::string &target):
Form("ShrubberyCreationForm", 145, 137, target)
{
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &copy):
Form(copy)
{
}

ShruberryCreationForm::~ShruberryCreationForm(void)
{
    //std::cout << "SC Destructor called" << std::endl;
}

ShruberryCreationForm&   ShruberryCreationForm::operator=(const ShruberryCreationForm &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->Form::operator=(rhs);
    return(*this);
}

void ShruberryCreationForm::execute(Bureaucrat const & executor) const throw(std::ios_base::failure, GradeTooLowException, NotSignedException)
{
    this->Form::execute(executor); // throws exceptions
    
    std::stringstream file_name;
    file_name << this->getTarget() << "_shrubbery";
    
    std::ofstream file;
    file.exceptions(std::ofstream::failbit); // if failbit is set, make object throw an exception (of type ios_base::failure, which inherits from std::exception)
    file.open(file_name.str().c_str(), std::ofstream::trunc);
    
    file << "beautiful ascii trees";
}