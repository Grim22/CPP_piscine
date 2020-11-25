#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        Bureaucrat(void);
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        virtual ~Bureaucrat(void);
        Bureaucrat&  operator=(const Bureaucrat &copy);

        const std::string &getName() const;
        int getGrade() const;
        void incGrade();
        void decGrade();
        class GradeTooHighException: public std::exception
        {
            virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char *what() const throw();
        };
};

std::ostream & operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif