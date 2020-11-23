#ifndef Slave_H
# define Slave_H

#include "Victim.hpp"

class Slave: public Victim{
    public:
    Slave(const std::string &name = "unknown"); // default constructor
    Slave(const Slave &copy);
    virtual ~Slave(void);
    Slave&  operator=(const Slave &copy);
    virtual void getPolymorphed() const;  
};

#endif