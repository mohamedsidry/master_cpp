
#include "Fixed.hpp"


Fixed::Fixed():
fixedPoint(0)
{
    announce("Default constructor called");
}

Fixed::Fixed(const int nbr):
fixedPoint(nbr << bitsFract)
{
    announce("int constructor called");
}

Fixed::Fixed(const Fixed& other)
{
    announce("Copy constructor called");
    this->fixedPoint = other.fixedPoint;
}

Fixed::Fixed(const float nbr)
{
    announce("float constructor called");
    fixedPoint = static_cast<int>(roundf(nbr * (1U << bitsFract)));
}



// OPERATORES
Fixed& Fixed::operator=(const Fixed& other)
{
    announce("Copy assignment operator called");
    if (this != &other)
        this->fixedPoint = other.fixedPoint;
    return *this;
}


Fixed::~Fixed()
{
    announce("Destructor called");
}




// MEMBER METHODES 


int Fixed::toInt(void) const
{
    return (fixedPoint >> bitsFract);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(fixedPoint) / (1U << bitsFract));
}


std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}


void Fixed::announce(const std::string& message) const
{
    std::cout << message << std::endl;
}
/**
 * getSign: get the sign of float number positive or negative .
 * desc : take float number stor it in union shift it by 31 so the most sig bit bacome less sig bit
 *        return num bitwise 1
 * arg: float number !
 * return: ether {0, 1} , 0 means positive number .
 * v
 * 0 00111111 00000000000000000000000 +0.5 return (0) ;
 * v
 * 1 00111111 00000000000000000000000 -0.5 return (1) ;
 * 
 */

unsigned int Fixed::getFloatSign(float num)
{
    union rawBits {float f;unsigned int u;};
    rawBits raw;
    raw.f = num;
    return raw.u >> 31 & 0x1;
}

/**
 * 
 * getFloatExponent: get the exponent part of float number .
 * desc : take float number stor it in union remove sign shift it by 24 and
 *        bitwise with max value can be stored in 8bits to get the fraction part . 
 * arg: num float number !
 * return: ether {0...255}.
 *  (=127) num <= 0 ; (< 127) num < 0.0 ; (> 127) num > 0
 * v
 * {0,1} 00111111 00000000000000000000000 +0.5 return (0) ;
 * v
 * {0}   00000000 00000000000000000111111 -0.5 return (1) ;
 * 
 */
unsigned int Fixed::getFloatExponent(float num)
{
    union rawBits {float f;unsigned int u;};
    rawBits raw;
    raw.f = num;
    unsigned int exponent = raw.u << 1;
    return exponent >> 24 & 0xFF;
}

/**
 * 
 * getFloatMantisaa: get the mantisaa part of float number .
 * desc : take float number stor it in union shift it by sign bit + exponent bits and
 *        shift back to get the manti part . 
 * arg: num float number !
 * return: ether {0...2^23}.
 */
unsigned int Fixed::getFloatMantisaa(float num)
{
    union rawBits {float f;unsigned int u;};
    rawBits raw;
    raw.f = num;
    unsigned int mantisaa = raw.u << 9;
    return mantisaa >> 9;
}

/**
 * showRawBits : display number to standard output in binary form .
 * arg1 : number to be shown .
 * arg2 : size of it int bits .
 * return : ostream with numbers in bin form in it !
*/
std::ostream& Fixed::showRawBits(unsigned int nbr, size_t len)
{
    if (len == 0)
        return std::cout;
    else
    {
        showRawBits(nbr >> 1, len - 1);
        return std::cout << (nbr & 0x1);
    }
}




// GETTERS && SETTERS 

int Fixed::getRawBits(void) const
{
    //announce("getRawBits member function called");
    return fixedPoint;
}
void  Fixed::setRawBits(const int raw)
{
    //announce("setRawBits member function called");
    fixedPoint = raw;
}


