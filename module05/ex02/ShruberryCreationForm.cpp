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

void ShruberryCreationForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, NotSignedException)
{
    this->Form::execute(executor); // throws exceptions
    std::stringstream file_name;
    std::ofstream file;
    file_name << this->getTarget() << "_shrubbery";
    file.open(file_name.str().c_str(), std::ofstream::trunc);
    file << "message"; // ASCII threes
}