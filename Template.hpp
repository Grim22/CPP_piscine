#ifndef ${Header}_H
# define ${Header}_H

#include <iostream>
#include <string>

class $Class
{
    private:

    public:
        $Class(void);
        $Class(/*param*/);
        $Class(const $Class &copy);
        virtual ~$Class(void);
        $Class&  operator=(const $Class &copy);
};

std::ostream & operator<<(std::ostream &o, const $Class &rhs);

#endif