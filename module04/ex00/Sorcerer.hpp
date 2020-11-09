#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer{
    private:
    std::string name;
    std::string title;
    Sorcerer(void);
    public:
    Sorcerer(const std::string &name, const std::string &title);
    Sorcerer(const Sorcerer &copy);
    ~Sorcerer(void);
    Sorcerer&  operator=(const Sorcerer &copy);
    const std::string & get_name(void) const;
    const std::string & get_title(void) const;
    void polymorph(Victim const &target) const;
};

std::ostream & operator<<(std::ostream &o, const Sorcerer &copy);

#endif