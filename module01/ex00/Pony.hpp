# ifndef PONNY_H
#define PONNY_H

#include <string>

class Pony 
{
public:
    Pony(std::string color, std::string name, std::string origin, std::string fav_meal, int age)  ;
    ~Pony(void);
    std::string color;
    std::string name;
    std::string origin;
    std::string fav_meal;
    int age;
};

#endif