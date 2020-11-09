#ifndef PEON_H
# define PEON_H

#include "Victim.hpp"

class Peon: public Victim{
    public:
    Peon(const std::string &name);
    Peon(const Peon &copy);
    ~Peon(void);
    Peon&  operator=(const Peon &copy);
    void getPolymorphed() const;  
};

#endif