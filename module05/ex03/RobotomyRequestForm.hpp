#ifndef RobotomyRequestForm_H
# define RobotomyRequestForm_H

#include <iostream>
#include <string>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
    private:
        RobotomyRequestForm(void);

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm&  operator=(const RobotomyRequestForm &copy);
        
        virtual void execute(Bureaucrat const & executor) const throw(std::ios_base::failure, NotSignedException, GradeTooLowException);
};

#endif