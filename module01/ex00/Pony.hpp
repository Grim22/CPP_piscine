# ifndef PONNY_H
#define PONNY_H

#include <string>

class Pony 
{
    std::string color;
    std::string name;
    std::string origin;
    std::string fav_meal;
    int age;
public:
    Pony(std::string color, std::string name, std::string origin, std::string fav_meal, int age)  ;
    ~Pony(void);
    int get_age() const;
};

#endif