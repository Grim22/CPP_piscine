#ifndef FIXED_H
# define FIXED_H

class Fixed{
    private:
    int value;
    static const int num_fract_bit;

    public:
    Fixed(void);
    Fixed(const Fixed &copy);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    Fixed&  operator=(const Fixed &copy);
};

#endif