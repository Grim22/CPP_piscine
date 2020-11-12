#ifndef PEON_H
# define PEON_H

#include "Victim.hpp"

class Peon: public Victim{
    public:
    Peon(const std::string &name = "unknown");
    Peon(const Peon &copy);
    virtual ~Peon(void);
    Peon&  operator=(const Peon &copy);
    virtual void getPolymorphed() const;  
};

#endif