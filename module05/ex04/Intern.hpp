#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include <string>
class Form;

class Intern
{
    private:
        static const std::string form_names[3];
        Form* create_shrub(const std::string &target);
        Form* create_rob(const std::string &target);
        Form* create_pres(const std::string &target);

    public:
        class FormTypeNotFoundException: public std::exception
        {
            virtual const char *what() const throw();
        };

        Intern(void);
        Intern(const Intern &copy);
        virtual ~Intern(void);
        Intern&  operator=(const Intern &copy);

        Form *makeForm(const std::string &form_name, const std::string &target);
};

#endif