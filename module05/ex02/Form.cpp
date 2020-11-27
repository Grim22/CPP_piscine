#include "Form.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExec, const std::string &target) throw(GradeTooLowException, GradeTooHighException):
name(name), is_signed(false), grade_sign(gradeSign), grade_exec(gradeExec), target(target)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    else if (gradeExec > 150 || gradeSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy):
name(copy.name), is_signed(copy.is_signed), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec), target(copy.target)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Form::~Form(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Form&   Form::operator=(const Form &rhs)
{
    //std::cout << "Assignement operator called" << std::endl;
    this->is_signed = rhs.is_signed;
    this->target = rhs.target;
    return(*this);
}

std::ostream & operator<<(std::ostream &o, const Form &rhs)
{
    o << rhs.getName();
    if (rhs.getIsSigned() == false)
        o << ", unsigned,";
    else
        o << ", signed,";
    o << " target: " << rhs.getTarget();
    o << ", grade required to sign: " << rhs.getGradeSign() << ", grade required to exec: " << rhs.getGradeExec() << std::endl;
    return o;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form::GradeTooHigh exception found");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form::GradeTooLow exception found");
}

const char *Form::NotSignedException::what() const throw()
{
    return ("Form::Not signed exception found");
}

int Form::getGradeSign() const
{
    return this->grade_sign;
}

int Form::getGradeExec() const
{
    return this->grade_exec;
}

bool Form::getIsSigned() const
{
    return this->is_signed;
}

const std::string &Form::getName() const
{
    return this->name;
}

const std::string &Form::getTarget() const
{
    return this->target;
}

void Form::beSigned(const Bureaucrat &bureau) throw(GradeTooLowException)
{
    if (bureau.getGrade() > this->grade_sign)
        throw GradeTooLowException();
    else
        this->is_signed = true;
}

void Form::execute(const Bureaucrat& executor) const throw(NotSignedException, GradeTooLowException, std::ios_base::failure)
{
    if (executor.getGrade() > this->grade_exec)
        throw GradeTooLowException();
    else if (this->is_signed == false)
        throw NotSignedException();
}