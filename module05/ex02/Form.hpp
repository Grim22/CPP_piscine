#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_sign;
        const int grade_exec;
        std::string target;
        Form(void); // constructor with no argument is in private (cant be accessed from outside) and is not defined in the .cpp (can't be accessed internally: will produce a link errror) = explicitly forbidden to use default constructor

    public:

        class GradeTooHighException: public std::exception
        {
            virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char *what() const throw();
        };
        class NotSignedException: public std::exception
        {
            virtual const char *what() const throw();
        };

        Form(const std::string &name, int grade_sign, int grade_exec, const std::string &target) throw(GradeTooHighException, GradeTooLowException);
        Form(const Form &copy);
        virtual ~Form(void);
        Form&  operator=(const Form &copy);

        int getGradeSign() const;
        int getGradeExec() const;
        bool getIsSigned() const;
        const std::string &getName() const;
        const std::string &getTarget() const;

        void beSigned(const Bureaucrat&) throw(GradeTooLowException);
        virtual void execute(Bureaucrat const & executor) const throw(GradeTooLowException, NotSignedException) = 0; 
        // declared '= 0' to force implementation at derived class level (the class must be abstract, acording to the subject), but still defined in the CPP to provide a common behaviour
};

std::ostream & operator<<(std::ostream &o, const Form &rhs);

#endif