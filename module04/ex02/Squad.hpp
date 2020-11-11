#ifndef SQUAD_H
# define SQUAD_H

#include <iostream>
#include <string>
#include <ISquad.hpp>

// typedef struct s_list
// {
//     void *content;
//     struct s_list *next;
// }               t_list;

class Squad: public ISquad
{
    private:
        ISpaceMarine **tab; // could also be done with chained list
        int count;

    public:
        Squad(void);
        // Squad(ISpaceMarine*);
        Squad(const Squad &copy);
        virtual ~Squad(void);
        virtual int getCount() const;
        virtual ISpaceMarine* getUnit(int) const;
        virtual int push(ISpaceMarine*);
        Squad&  operator=(const Squad &copy);
};

std::ostream & operator<<(std::ostream &o, const Squad &rhs);

#endif