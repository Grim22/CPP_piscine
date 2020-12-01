#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

#include <iostream>
#include <string>

class Bureaucrat;
class Intern;
class Form;

class OfficeBlock
{
    private:
        OfficeBlock(const OfficeBlock &copy);
        OfficeBlock&  operator=(const OfficeBlock &copy);
        Intern const *intern; // should use pointers rather than reference because reference are const while we need to be able to change intern and bureaucrats
        Bureaucrat const *sign_b; // pointers to const objects
        Bureaucrat const *exec_b;
        Form *form; // office block can only deal with one form at a time (once a new form is created, the old form is deleted)

    public:
        class NullPointerException: public std::exception
        {
            virtual const char* what() const throw();
        };
        OfficeBlock(void);
        OfficeBlock(Intern *intern, Bureaucrat *signing_b, Bureaucrat *executing_b);
        ~OfficeBlock(void);

        void addIntern(Intern *intern);
        void addSignB(Bureaucrat *bur);
        void addExec(Bureaucrat *bur);
        void doBureaucracy(const std::string &form_name, const std::string &target);
};

#endif