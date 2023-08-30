#include "Fixed.hpp"

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
    return (_fixedPointValue * obj._fixedPointValue);
}

float Fixed::operator/(const Fixed &obj) const
{
    return (_fixedPointValue / obj._fixedPointValue);
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &other)
        return (*this);
    this->_fixedPointValue = other._fixedPointValue;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_fixedPointValue / (float)pow(2, nmbOfFractionalBits));
}

int Fixed::toInt(void) const
{
    return (_fixedPointValue / pow(2, nmbOfFractionalBits));
}

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = x * pow(2, nmbOfFractionalBits); // e.g. 5 to 5.00 becomes 20 because 20 = 5*2^2
}

Fixed::Fixed(const float x) : _fixedPointValue(roundf((x * pow(2, nmbOfFractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
    // e.g. 5 to 5.00 becomes 20 because 20 = 5*2^2
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}