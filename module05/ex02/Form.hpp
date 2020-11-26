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

        Form(const std::string &name, int grade_sign, int grade_exec) throw(GradeTooHighException, GradeTooLowException);
        // throw(...) at the end is an optionnal "exception specification". 
        // Note (cf https://bruce-eckel.developpez.com/livres/cpp/ticpp/v2/?page=page_2):
        // "You're not required to inform the people using your function what exceptions you might throw. 
        // However, failure to do so can be considered uncivilized because it means that users cannot be sure what code to write to catch all potential exceptions. 
        // If they have your source code, they can hunt through and look for throw statements, but often a library doesn't come with sources. Good documentation can help alleviate this problem, but how many software projects are well documented? 
        // C++ provides syntax to tell the user the exceptions that are thrown by this function, so the user can handle them. 
        // This is the optional exception specification, which adorns a function's declaration, appearing after the argument list."
        Form(const Form &copy);
        virtual ~Form(void);
        Form&  operator=(const Form &copy);

        int getGradeSign() const;
        int getGradeExec() const;
        bool getIsSigned() const;
        const std::string &getName() const;

        void beSigned(const Bureaucrat&) throw(GradeTooLowException);
};

std::ostream & operator<<(std::ostream &o, const Form &rhs);

#endif