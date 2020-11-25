#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        Bureaucrat(void);
    public:
        class GradeTooHighException: public std::exception
        {
            virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char *what() const throw();
        };
        Bureaucrat(const std::string &name, int grade) throw(GradeTooLowException, GradeTooHighException);
        Bureaucrat(const Bureaucrat &copy);
        virtual ~Bureaucrat(void);
        Bureaucrat&  operator=(const Bureaucrat &copy);

        const std::string &getName() const;
        int getGrade() const;
        void signForm(Form&) const;
        void incGrade() throw(GradeTooHighException);
        void decGrade() throw(GradeTooLowException);
};

std::ostream & operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif