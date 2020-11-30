#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include <string>

class Intern
{
    private:

    public:
        Intern(void);
        Intern(/*param*/);
        Intern(const Intern &copy);
        virtual ~Intern(void);
        Intern&  operator=(const Intern &copy);
};

std::ostream & operator<<(std::ostream &o, const Intern &rhs);

#endif