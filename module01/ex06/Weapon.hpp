# ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
    std::string     type;

public:
    const std::string&    getType() const;
    void            setType(std::string type);
    Weapon(std::string type);
    ~Weapon(void);
};

# endif