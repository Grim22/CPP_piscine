#ifndef ENEMY_H
# define ENEMY_H

#include <string>

class Enemy
{
    private:
        int hp;
        std::string type;

    public:
        Enemy(void);
        Enemy(int hp, std::string const & type);
        Enemy(const Enemy &copy);
        virtual ~Enemy(void);
        int getHP() const;
        const std::string & gettype() const;
        virtual void takeDamage(int);
        Enemy&  operator=(const Enemy &copy);
};

#endif