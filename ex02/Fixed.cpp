#include "Fixed.hpp"

bool Fixed::operator<(const Fixed &obj) const
{
    return (toFloat() < obj.toFloat());
}

bool Fixed::operator>(const Fixed &obj) const
{
    return (toFloat() > obj.toFloat());
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (toFloat() < obj.toFloat());
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (toFloat() > obj.toFloat());
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (toFloat() == obj.toFloat());
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (toFloat() != obj.toFloat());
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}

float Fixed::operator+(const Fixed &obj) const
{
    return (toFloat() + obj.toFloat());
}

float Fixed::operator-(const Fixed &obj) const
{
    return (toFloat() - obj.toFloat());
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
    _fixedPointValue += EPSILON;
    return (*this);
}

Fixed Fixed::operator++(int x)
{
    Fixed tmp = *this;

    _fixedPointValue += EPSILON;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    _fixedPointValue -= EPSILON;
    return (*this);
}

Fixed Fixed::operator--(int x)
{
    Fixed tmp = *this;

    _fixedPointValue -= EPSILON;
    return (tmp);
}

Fixed &Fixed::min(Fixed &nmb1, Fixed &nmb2)
{
    if (nmb1.toFloat() < nmb2.toFloat())
        return (nmb1);
    return (nmb2);
}

const Fixed &Fixed::min(const Fixed &nmb1, const Fixed &nmb2)
{
    if (nmb1.toFloat() < nmb2.toFloat())
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
    // std::cout << "Assignation operator called" << std::endl;
    if (this == &other)
        return (*this);
    this->_fixedPointValue = other._fixedPointValue;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_fixedPointValue / (float)(1 << this->nmbOfFractionalBits));
}

int Fixed::toInt(void) const
{
    return (_fixedPointValue >> this->nmbOfFractionalBits);
}

Fixed::Fixed():_fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    // std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = x * (1 << this->nmbOfFractionalBits); // e.g. 5 to 5.00 becomes 20 because 20 = 5*2^2
}

Fixed::Fixed(const float x):_fixedPointValue(roundf((x * (1 << this->nmbOfFractionalBits))))
{
    // std::cout << "Float constructor called" <<std::endl;
    //e.g. 5 to 5.00 becomes 20 because 20 = 5*2^2
}

Fixed::Fixed(const Fixed &other):_fixedPointValue(other._fixedPointValue)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}