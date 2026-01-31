
#include "Fixed.hpp"

/**
 * @brief Fixed: default constructor .
 * @details: set attributes to default values .
 * @param no_params
 * @return nothing .
 * 
*/
Fixed::Fixed():
fixedPoint(0)
{
    announce("Default constructor called");
}

/**
 * @brief Fixed: copy constructor .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return nothing .
*/

Fixed::Fixed(const Fixed& other)
{
    announce("Copy constructor called");
    this->fixedPoint = other.fixedPoint;
}


/**
 * @brief Fixed: copy assignment operator .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return new object !
*/
Fixed& Fixed::operator=(const Fixed& other)
{
    announce("Copy assignment operator called");
    if (this != &other)
        this->fixedPoint = other.fixedPoint;
    return *this;
}


// GETTERS && SETTERS 

/**
 * @brief getRawBit: get the raw value of fixedPoint .
 * @param no_params
 * @return the value in fixedPoint attribute .
*/
int Fixed::getRawBits(void) const
{
    announce("getRawBits member function called");
    return fixedPoint;
}

/**
 * @brief setRawBit: set the value of fixedPoint .
 * @param [in] raw: the new value of fixedPoint attribute .
 * @return nothing .
*/

void  Fixed::setRawBits(const int raw)
{
    fixedPoint = raw;
    announce("setRawBits member function called");
}


/**
 * @brief Fixed: default destructor .
 * @details: release the resourses .
 * @param no_params
 * @return nothing .
*/
Fixed::~Fixed()
{
    announce("Destructor called");
}

/**
 * @brief announce: dispaly message .
 * @details: display text message to stdout .
 * @param [in] message: text to display !
 * @return nothing .
*/
void Fixed::announce(const std::string& message) const
{
    std::cout << message << std::endl;
}
