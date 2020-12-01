#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
Form("RobotomyRequestForm", 72, 45, target)
{
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
Form(copy)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    //std::cout << "SC Destructor called" << std::endl;
}

RobotomyRequestForm&   RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    this->Form::operator=(rhs);
    return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, NotSignedException)
{
    this->Form::execute(executor); // throws exceptions
    std::cout << "*******DRIIIIIILING NOISE*********" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Failure to robotomize target !" << std::endl;
}