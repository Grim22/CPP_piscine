#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

OfficeBlock::OfficeBlock(void):
intern(NULL), sign_b(NULL), exec_b(NULL), form(NULL)
{
    //std::cout << "Default constructor called" << std::endl;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signing_b, Bureaucrat *executing_b):
intern(intern), sign_b(signing_b), exec_b(executing_b), form(NULL)
{
    //std::cout << "Param constructor called" << std::endl;
}

OfficeBlock::~OfficeBlock(void)
{
    if (this->form)
    {
        delete this->form;
        this->form = NULL;
    }
    //std::cout << "Destructor called" << std::endl;
}

void OfficeBlock::addIntern(Intern *intern)
{
    this->intern = intern;
}
void OfficeBlock::addSignB(Bureaucrat *bur)
{
    this->sign_b = bur;
}
void OfficeBlock::addExec(Bureaucrat *bur)
{
    this->exec_b = bur;
}

void OfficeBlock::doBureaucracy(const std::string &form_name, const std::string &target)
{
    if (this->intern == NULL)
        throw NullPointerException();
    if (this->form)
    {
        delete form;
        form = NULL;
    }
    this->form = this->intern->makeForm(form_name, target);
    if (this->sign_b == NULL)
        throw NullPointerException();
    this->sign_b->signForm(*this->form);
    if (this->exec_b == NULL)
        throw NullPointerException();
    this->exec_b->executeForm(*this->form);
}

const char* OfficeBlock::NullPointerException::what() const throw()
{
    return "OfficeBlock NullPointerException found";
}