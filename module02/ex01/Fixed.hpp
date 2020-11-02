#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed{
    private:
    int value;
    static const int num_fract_bit;

    public:
    Fixed(void);
    Fixed(const int);
    Fixed(const float);
    Fixed(const Fixed &copy); // prend une reference (const) sur Fixed en parametre, et non une copie. Raison: s'il prenait une copie en parametre, il faudrait faire appel au copy constructor pour creer cette copie !
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    Fixed&  operator=(const Fixed &copy); // on renvoie l'instance courante modifiee (reference), ce qui permet de "chainer" les '=' (a = b = c = d) 
};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs); // ne peut pas etre defini comme une fonction membre, car supposerait que le parametre de gauche de l'operateur (un ostream) est une instance de la classe
// on renvoie le ostream modifie (reference), afin de pouvoir chainer les <<

// Rq: operator overloading: pourquoi une reference en parametre et non une copie: plus efficace: on utilise l'objet existant plutot que davoir a en creer une copie !

#endif