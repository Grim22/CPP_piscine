#include "Intern.hpp"
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

const std::string Intern::form_names[3] = {"shruberry creation", "robotomy request", "presidential pardon"};

Intern::Intern(void)
{
    //std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
    //std::cout << "Copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Destructor called" << std::endl;
}

Intern&   Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    //std::cout << "Assignement operator called" << std::endl;
    return(*this);
}

Form *Intern::makeForm(const std::string &form_name, const std::string &target)
{
    Form *intern(NULL);
    Form* (Intern::*form_objs[3])(const std::string &target) = {&Intern::create_shrub, &Intern::create_rob, &Intern::create_pres};

    for (size_t i = 0; i < 3; i++)
    {
        if (form_name == this->form_names[i])
            intern = (this->*form_objs[i])(target);
    }
    if (intern == NULL)
        throw FormTypeNotFoundException();
    
    return intern;
}

const char *Intern::FormTypeNotFoundException::what() const throw()
{
    return "Form Type Not Found Exception raised";
}

Form* Intern::create_shrub(const std::string &target)
{
    return new ShruberryCreationForm(target);
}

Form* Intern::create_rob(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

Form* Intern::create_pres(const std::string &target)
{
    return new PresidentialPardonForm(target);
}
