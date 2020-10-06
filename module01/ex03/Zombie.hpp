#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie
{
    std::string type;
    std::string name;

public:
    Zombie(void);
    ~Zombie(void);
    void    announce(void) const;
    void    set_type(std::string type);   
    void    set_name(std::string name);
};

#endif