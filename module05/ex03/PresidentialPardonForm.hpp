#ifndef PresidentialPardonForm_H
# define PresidentialPardonForm_H

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        PresidentialPardonForm(void);

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm&  operator=(const PresidentialPardonForm &copy);
        
        virtual void execute(Bureaucrat const & executor) const throw(std::ios_base::failure, NotSignedException, GradeTooLowException);
};

#endif