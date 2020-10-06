# ifndef PONNY_H
#define PONNY_H

#include <string>

class Pony 
{
    std::string color;
    std::string name;
public:
    Pony(std::string color, std::string name)  ;
    ~Pony(void);
    void    announce(void) const;
};

#endif