
#include "Fixed.hpp"

Fixed::Fixed():
fixedPoint(0)
{
    announce("Default constructor called");
}


Fixed::Fixed(const Fixed& other)
{
    announce("Copy constructor called");
    this->fixedPoint = other.fixedPoint;
}


Fixed& Fixed::operator=(const Fixed& other)
{
    announce("Copy assignment operator called");
    if (this != &other)
        this->fixedPoint = other.fixedPoint;
    return *this;
}


// GETTERS && SETTERS 

int Fixed::getRawBits(void) const
{
    announce("getRawBits member function called");
    return fixedPoint;
}
void  Fixed::setRawBits(const int raw)
{
    fixedPoint = raw;
    announce("setRawBits member function called");
}


Fixed::~Fixed()
{
    announce("Destructor called");
}


void Fixed::announce(const std::string& message) const
{
    std::cout << message << std::endl;
}
