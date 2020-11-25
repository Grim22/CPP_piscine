#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
name(copy.name), grade(copy.grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Bureaucrat&   Bureaucrat::operator=(const Bureaucrat &rhs)
{
    this->grade = rhs.grade;
    return(*this);
}

std::ostream & operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return o;
}
        
const std::string &Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incGrade()
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decGrade()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception caught";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception caught";
}