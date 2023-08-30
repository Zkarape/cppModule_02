#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedPointValue;
    static const int nmbOfFractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
};

#endif