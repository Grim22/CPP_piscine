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

const std::string tree = "\
              v .   ._, |_  .,\n\
           `-._\\/  .  \\ /    |/_\n\
               \\\\  _\\, y | \\//\n\
         _\\_.___\\\\, \\\\/ -.\\||\n\
           `7-,--.`._||  / / ,\n\
           /'     `-. `./ / |/_.'\n\
                     |    |//\n\
                     |_    /\n\
                     |-   |\n\
                     |   =|\n\
                     |    |\n\
--------------------/ ,  . \\--------._\n\
";

void ShruberryCreationForm::execute(Bureaucrat const & executor) const throw(std::ios_base::failure, GradeTooLowException, NotSignedException)
{
    this->Form::execute(executor); // throws exceptions
    
    std::string const file_name = this->getTarget() + "_shruberry";
    
    std::ofstream file;
    file.exceptions(std::ofstream::failbit); // if failbit is set, make object throw an exception (of type ios_base::failure, which inherits from std::exception)
    file.open(file_name.c_str(), std::ofstream::trunc);
    file << tree;
    file.close();
}