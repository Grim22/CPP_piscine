
# ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "Brain.hpp"

class Human
{
private:
    const Brain brain;
public:
    Human(void);
    ~Human(void);
    const Brain &getBrain() const; // getbrain contient l'addresse de Brain (comme un pour un pointeur). Si on renvoie un objet de type brain (et non brain&), on va creer une copie de brain, avec une adresse differente. 
    std::string identify(void) const;
};

# endif