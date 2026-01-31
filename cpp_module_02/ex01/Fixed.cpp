
#include "Fixed.hpp"

/**
 * @brief Fixed: default constructor .
 * @details: set attributes to default values .
 * @param no_params
 * @return nothing !
*/
Fixed::Fixed():
fixedPoint(0)
{
    announce("Default constructor called");
}

/**
 * @brief Fixed: constructor that takes an int .
 * @details: set fixedPoint attributes to nbr .
 * @param [in] nbr number !
 * @return nothing !
*/
Fixed::Fixed(const int nbr):
fixedPoint(nbr << bitsFract)
{
    announce("int constructor called");
}
/**
 * @brief Fixed: copy constructor .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return nothing !
*/
Fixed::Fixed(const Fixed& other)
{
    announce("Copy constructor called");
    this->fixedPoint = other.fixedPoint;
}

/**
 * @brief Fixed: constructor that takes a float .
 * @details: set fixedPoint attributes to nbr .
 * @param [in] nbr number !
 * @return nothing !
*/
Fixed::Fixed(const float nbr)
{
    announce("float constructor called");
    fixedPoint = static_cast<int>(roundf(nbr * (1U << bitsFract)));
}

/**
 * @brief Fixed: default destructor .
 * @details: release the resourses .
 * @param no_params
 * @return nada !
*/
Fixed::~Fixed()
{
    announce("Destructor called");
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



/**
 * @brief toInt: extract int value from fixed point .
 * @param no_params
 * @return integer .
*/
int Fixed::toInt(void) const
{
    return (fixedPoint >> bitsFract);
}

/**
 * @brief toInt: extract real number from fixed point .
 * @param no_param .
 * @return integer .
*/
float Fixed::toFloat(void) const
{
    return (static_cast<float>(fixedPoint) / (1U << bitsFract));
}

/**
 * @brief operator<<: insert float number from obj to stream.
 * @param [in, out] os : output stream .
 * @param [in] obj : fixedpoint ref .
 * @return output stream with number inserted to it .
*/
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
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



/**
 * @brief getRawBit: get the raw value of fixedPoint .
 * @param no_params
 * @return the value in fixedPoint attribute .
*/
int Fixed::getRawBits(void) const
{
    //announce("getRawBits member function called");
    return fixedPoint;
}

/**
 * @brief setRawBit: set the value of fixedPoint .
 * @param [in] raw: the new value of fixedPoint attribute .
 * @return nothing .
*/
void  Fixed::setRawBits(const int raw)
{
    //announce("setRawBits member function called");
    fixedPoint = raw;
}



/**
 * @brief getSign: get the sign of float number positive or negative .
 * @param[in] num float number !
 * @return: ether {0, 1} , 0 means positive number .
 * @details:
 *  take float number stor it in union shift it by 31 so the most sig bit bacome less sig bit
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
 * @brief getFloatExponent: get the exponent part of float number .
 * @param[in] num float number !
 * @return ether {0...255}.
 * @details: take float number stor it in union remove sign shift it by 24 and
 *        bitwise with max value can be stored in 8bits to get the fraction part . 
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
 * @brief getFloatMantisaa: get the mantisaa part of float number .
 * @param[in] num float number !
 * @return ether {0...2^23}.
 * @details: take float number stor it in union shift it by sign bit + exponent bits and
 *        shift back to get the manti part . 
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
 * @brief showRawBits: display number to standard output in binary form .
 * @param[in] nbr : number to be shown .
 * @param[in] len : size of it int bits .
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
