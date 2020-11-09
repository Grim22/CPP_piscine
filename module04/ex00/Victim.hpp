#ifndef VICTIM_H
# define VICTIM_H

#include <iostream>
#include <string>

class Victim{
    private:
    std::string name;
    public:
    Victim(const std::string &name = "unknown victim");
    Victim(const Victim &copy);
    virtual ~Victim(void);
    // why "virtual" ? same explication as for getPolymorphed
    // the destructor is just like a member function, that is redefined in derived class(es)
    // if no virtual, and used through a pointer of base class (Victim), pointing to a Peon, call to Peon destructor will not be made, resulting in leaks
    Victim& operator=(const Victim &copy);
    const std::string & get_name(void) const;
    virtual void getPolymorphed() const; 
    // virtual because this member function is redefined in derived class (Peon).
    // with virtual, we ensure that the correct function is called (Victim::getPolymorphed or Peon::getPolymorphed) regardless of the type of pointer user for function call
    // more precisely: when it is called through a pointer to base class (Victim), pointing to an object of derived class (Peon)
    // if virtual was not specified, "robert.polymorph(joe)" (cf. main) would not be able to access Peon::getPolymorphed (as polymorph uses a reference to Victim)
};

std::ostream & operator<<(std::ostream &o, const Victim &rhs);

#endif