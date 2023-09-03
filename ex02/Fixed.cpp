#include "Fixed.hpp"

Fixed::Fixed():_fixedPointValue(0)
{
}

Fixed::Fixed(const int x)
{
    _fixedPointValue = x << this->nmbOfFractionalBits;
}

Fixed::Fixed(const float x):_fixedPointValue(roundf((x * (1 << this->nmbOfFractionalBits))))
{
}

Fixed::Fixed(const Fixed &other):_fixedPointValue(other._fixedPointValue)
{
}

int Fixed::getRawBits(void) const
{
    return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_fixedPointValue / (float)(1 << this->nmbOfFractionalBits));
}

int Fixed::toInt(void) const
{
    return (_fixedPointValue / pow(2, nmbOfFractionalBits));
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (_fixedPointValue < obj._fixedPointValue);
}

bool Fixed::operator>(const Fixed &obj) const
{
    return (_fixedPointValue > obj._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (_fixedPointValue < obj._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (_fixedPointValue > obj._fixedPointValue);
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (_fixedPointValue == obj._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (_fixedPointValue != obj._fixedPointValue);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}

float Fixed::operator+(const Fixed &obj) const
{
    return (_fixedPointValue + obj._fixedPointValue);
}

float Fixed::operator-(const Fixed &obj) const
{
    return (_fixedPointValue - obj._fixedPointValue);
}

float Fixed::operator*(const Fixed &obj) const
{
    return (toFloat() * obj.toFloat());
}

float Fixed::operator/(const Fixed &obj) const
{
    return (toFloat() / obj.toFloat());
}

Fixed &Fixed::operator++()
{
    _fixedPointValue += 1;
    return (*this);
}

Fixed Fixed::operator++(int x)
{
    Fixed tmp = *this;

    _fixedPointValue += 1;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    _fixedPointValue -= 1;
    return (*this);
}

Fixed Fixed::operator--(int x)
{
    Fixed tmp = *this;

    _fixedPointValue -= 1;
    return (tmp);
}

Fixed &Fixed::min(Fixed &nmb1, Fixed &nmb2)
{
    if (nmb1._fixedPointValue < nmb2._fixedPointValue)
        return (nmb1);
    return (nmb2);
}

const Fixed &Fixed::min(const Fixed &nmb1, const Fixed &nmb2)
{
    if (nmb1._fixedPointValue < nmb2._fixedPointValue)
        return (nmb1);
    return (nmb2);
}

Fixed &Fixed::max(Fixed &nmb1, Fixed &nmb2)
{
    if (nmb1.toFloat() > nmb2.toFloat())
        return (nmb1);
    return (nmb2);
}

const Fixed &Fixed::max(const Fixed &nmb1, const Fixed &nmb2)
{
    if (nmb1.toFloat() > nmb2.toFloat())
        return (nmb1);
    return (nmb2);
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this == &other)
        return (*this);
    this->_fixedPointValue = other._fixedPointValue;
    return (*this);
}

Fixed::~Fixed()
{
}
