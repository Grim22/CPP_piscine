#include "Form.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExec) throw(GradeTooLowException, GradeTooHighException):
name(name), is_signed(false), grade_sign(gradeSign), grade_exec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    else if (gradeExec > 150 || gradeSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy):
name(copy.name), is_signed(copy.is_signed), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Form::~Form(void)
{
    //std::cout << "Form Destructor called" << std::endl;
}

Form&   Form::operator=(const Form &rhs)
{
    //std::cout << "Assignement operator called" << std::endl;
    this->is_signed = rhs.is_signed;
    return(*this);
}

std::ostream & operator<<(std::ostream &o, const Form &rhs)
{
    o << rhs.getName();
    if (rhs.getIsSigned() == false)
        o << ", unsigned,";
    else
        o << ", signed,";
    o << " grade required to sign: " << rhs.getGradeSign() << ", grade required to exec: " << rhs.getGradeExec() << std::endl;
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

const char *Form::AlreadySigned::what() const throw()
{
    return ("Form::AlreadySigned exception found");
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

void Form::beSigned(const Bureaucrat &bureau) throw(GradeTooLowException, AlreadySigned)
{
    if (this->is_signed == true)
        throw AlreadySigned();
    if (bureau.getGrade() > this->grade_sign)
        throw GradeTooLowException();
    else
        this->is_signed = true;
}