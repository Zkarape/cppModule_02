#include "Fixed.hpp"

Fixed& Fixed::operator=(const Fixed &other)
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

Fixed::Fixed() 
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}