#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <cstdio>

class Fixed
{
private:
    int _fixedPointValue;
    static const int nmbOfFractionalBits = 8;

public:
    Fixed();
    Fixed(const int x);
    Fixed(const float x);
    Fixed(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed &operator=(const Fixed &other);
    ~Fixed();
};

std::ostream &operator<<(std::ostream &o, const Fixed &obj);

#endif
