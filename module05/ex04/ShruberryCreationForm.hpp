#ifndef SHRUBERRYCREATIONFORM_H
# define SHRUBERRYCREATIONFORM_H

#include <iostream>
#include <string>
#include "Form.hpp"

class ShruberryCreationForm: public Form
{
    private:
        ShruberryCreationForm(void);

    public:
        ShruberryCreationForm(const std::string &target);
        ShruberryCreationForm(const ShruberryCreationForm &copy);
        virtual ~ShruberryCreationForm(void);
        ShruberryCreationForm&  operator=(const ShruberryCreationForm &copy);
        
        virtual void execute(Bureaucrat const & executor) const throw(std::ios_base::failure, NotSignedException, GradeTooLowException);
};

#endif