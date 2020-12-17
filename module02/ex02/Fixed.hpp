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
    bool    operator>(const Fixed &rhs) const;
    bool    operator<(const Fixed &rhs) const;
    bool    operator>=(const Fixed &rhs) const;
    bool    operator<=(const Fixed &rhs) const;
    bool    operator==(const Fixed &rhs) const;
    bool    operator!=(const Fixed &rhs) const;
    Fixed&  operator=(const Fixed &rhs); // on renvoie l'instance courante modifiee (reference car c'est plus efficace quune copie), ce qui permet de "chainer" les '=' (a = b = c = d)
    Fixed   operator+(const Fixed &rhs) const; // renvoie une copie (et non une reference: on ne peut pas car c'est un "temporary object"**) de l'instance cree dans la fonction
    Fixed   operator-(const Fixed &rhs) const;
    Fixed   operator*(const Fixed &rhs) const;
    Fixed   operator/(const Fixed &rhs) const;
    Fixed&  operator++(); // Pre fix incrementation (++a) modifies the current instance and returns it. To be able to do: a = ++b;
    Fixed&  operator--(); 
    Fixed   operator++(int); // Post fix incrementation (a++) modifies the current instance but returns a copy of the current instance before it was modificated. Cant return a reference to local variable created
    Fixed   operator--(int); // The int parameter is a dummy parameter used to differentiate between prefix and postfix versions of the operators
    static const Fixed& min(Fixed const &a, Fixed const &b);       
    static Fixed&       min(Fixed &a, Fixed &b);       
    static const Fixed& max(Fixed const &a, Fixed const &b);       
    static Fixed&       max(Fixed &a, Fixed &b);       
};

std::ostream&   operator<<(std::ostream &o, Fixed const &rhs); // ne peut pas etre defini comme une fonction membre, car supposerait que le parametre de gauche de l'operateur (un ostream) est une instance de la classe
// on renvoie le ostream modifie (reference car plus efficace qu'une copie), afin de pouvoir chainer les << 


// Rq: operator overloading: pourquoi une reference en parametre et non une copie: plus efficace: on utilise l'objet existant plutot que davoir a en creer une copie ! (une fonction qui renvoie un objet en cree une copie)
//**https://docs.microsoft.com/en-us/cpp/cpp/temporary-objects?view=vs-2019. "These temporary objects are created only if your program does not copy the return value to an object"
#endif