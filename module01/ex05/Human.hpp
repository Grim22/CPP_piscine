
# ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "Brain.hpp"

class Human
{
private:
    Brain brain;
public:
    Human(void);
    ~Human(void);
    Brain &getBrain(); // getbrain contient l'addresse de Brain (comme un pour un pointeur). Si on renvoie un objet de type brain (et non brain&), on va creer une copie de brain, avec une adresse differente. 
    std::string identify(void);
};

# endif