#include "Fixed.hpp"

/**
 * @brief Fixed: default constructor .
 * @details: set attributes to default values .
 * @param no_params
 * @return nothing !
*/
Fixed::Fixed(): fixedPoint(0){}

/**
 * @brief Fixed: constructor that takes an int .
 * @details: set fixedPoint attributes to nbr .
 * @param [in] nbr number !
 * @return nothing !
*/
Fixed::Fixed(const int nbr): fixedPoint(nbr << bitsFract){}

/**
 * @brief Fixed: copy constructor .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return nothing !
*/
Fixed::Fixed(const Fixed& other){this->fixedPoint = other.fixedPoint;}

/**
 * @brief Fixed: constructor that takes a float .
 * @details: set fixedPoint attributes to nbr .
 * @param [in] nbr number !
 * @return nothing !
*/
Fixed::Fixed(const float nbr){fixedPoint = static_cast<int>(roundf(nbr * (1U << bitsFract)));}

/**
 * @brief Fixed: default destructor .
 * @details: release the resourses .
 * @param no_params
 * @return nada !
*/
Fixed::~Fixed()
{
    //announce("Destructor called");
}


// OPERATORES

/**
 * @brief Fixed: copy assignment operator .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return new object !
*/
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->fixedPoint = other.fixedPoint;
    return *this;
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
 * @brief operator>: compare two fixed points.
 * @param [in] ref : fixed point ref .
 * @return is this obj greater then ref .
*/
bool Fixed::operator>(const Fixed& ref) const
{
    return (this->getRawBits() > ref.getRawBits());
}

/**
 * @brief operator>=: compare two fixed points.
* @param [in] ref : fixed point ref .
 * @return is this obj greater or equal to ref .
*/
bool Fixed::operator>=(const Fixed& ref) const
{
    return (this->getRawBits() >= ref.getRawBits());
}

/**
 * @brief operator<: compare two fixed points.
 * @param [in] ref : fixed point ref .
 * @return is this obj less then ref .
*/
bool Fixed::operator<(const Fixed& ref) const
{
    return ( this->getRawBits() <  ref.getRawBits());
}

/**
 * @brief operator<=: compare two fixed points.
 * @param [in] ref : fixed point ref .
 * @return is this obj less or equal to ref .
*/
bool Fixed::operator<=(const Fixed& ref) const
{
    return ( this->getRawBits() <=  ref.getRawBits());
}

/**
 * @brief operator==: compare two fixed points.
  * @param [in] ref : fixed point ref .
 * @return is this obj equal to ref .
*/
bool Fixed::operator==(const Fixed& ref) const
{
    return ( this->getRawBits() ==  ref.getRawBits());
}

/**
 * @brief operator!=: compare two fixed points.
 * @param [in] ref : fixed point ref .
 * @return is this obj not equal to ref .
*/
bool Fixed::operator!=(const Fixed& ref) const
{
    return (this->getRawBits() !=  ref.getRawBits());
}

/**
 * @brief operator*: multiplay two fixed points.
 * @param [in] ref : fixed point ref .
 * @return result of multiplication .
*/
Fixed Fixed::operator*(const Fixed& ref) const
{
    Fixed result;

    long raw = static_cast<long>(this->getRawBits()) * static_cast<long>(ref.getRawBits());
    result.setRawBits(raw >> this->bitsFract);
    return result;
}

/**
 * @brief operator/: divide fp1 by fp2.
 * @param [in] ref : fixed point ref .
 * @protected throw exaption in case of Division by 0 .
 * @return result of Division .
*/
Fixed Fixed::operator/(const Fixed& ref) const
{
    Fixed result;
    if (ref.getRawBits() == 0)
        throw std::logic_error("Division by zero");
    result.setRawBits((this->getRawBits() << this->bitsFract) / ref.getRawBits());
    return (result);
}

/**
 * @brief operator+: addition of two fixed points.
  * @param [in] ref : fixed point ref .
 * @return result of addition .
*/
Fixed Fixed::operator+(const Fixed& ref) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + ref.getRawBits());
    return (result);
}

/**
 * @brief operator-: subtraction of two fixed points.
 * @param [in] ref : fixed point ref .
 * @return result of subtraction .
*/
Fixed Fixed::operator-(const Fixed& ref) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - ref.getRawBits());
    return (result);
}

/**
 * @brief operator++: post increment .
 * @param no_params .
 * @return object after increment .
*/
Fixed& Fixed::operator++()
{
    this->setRawBits(fixedPoint + 1);
    return *this;
}

/**
 * @brief operator++: pre increment .
 * @param no_params . we only add int to differ between pre and post 
 * @return object before increment .
*/
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->setRawBits(this->getRawBits() + 1);
    return (tmp);
}

/**
 * @brief operator--: post decrement .
 * @param no_params .
 * @return object after decrement .
*/
Fixed& Fixed::operator--()
{
    this->setRawBits(fixedPoint - 1);
    return *this;
}

/**
 * @brief operator--: pre decrement .
 * @param no_params . we only add (int) to differ between pre and post 
 * @return object before decrement .
*/
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->setRawBits(this->getRawBits() - 1);
    return (tmp);
}







// MEMBER METHODES 


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
 * @brief min: get the min fixedpoint of two fixed point.
 * @param [in] fp1 fixedpoint 1 .
 * @param [in] fp2 fixedpoint 2 .
 * @return small one .
*/
Fixed& Fixed::min(Fixed& fp1, Fixed& fp2)
{    
    return fp1 > fp2 ? fp2 : fp1; 
}

/**
 * @brief min: get the max fixedpoint of two fixed point.
 * @param [in] fp1 fixedpoint 1 .
 * @param [in] fp2 fixedpoint 2 .
 * @return big one .
*/
Fixed& Fixed::max(Fixed& fp1, Fixed& fp2)
{    
    return fp1 > fp2 ? fp1 : fp2; 
}

/**
 * @brief min: get the min fixedpoint of two fixed point.
 * @param [in] fp1 fixedpoint 1 .
 * @param [in] fp2 fixedpoint 2 .
 * @return small one .
*/
const Fixed& Fixed::min(const Fixed& fp1, const Fixed& fp2)
{   
    return fp1 > fp2 ? fp2 : fp1; 
}

/**
 * @brief min: get the max fixedpoint of two fixed point.
 * @param [in] fp1 fixedpoint 1 .
 * @param [in] fp2 fixedpoint 2 .
 * @return big one .
*/
const Fixed& Fixed::max(const Fixed& fp1, const Fixed& fp2)
{    
    return fp1 > fp2 ? fp1 : fp2; 
}

/**
 * @brief getRawBit: get the raw value of fixedPoint .
 * @param no_params
 * @return the value in fixedPoint attribute .
*/
int Fixed::getRawBits(void) const{return fixedPoint;}

/**
 * @brief setRawBit: set the value of fixedPoint .
 * @param [in] raw: the new value of fixedPoint attribute .
 * @return nothing .
*/
void  Fixed::setRawBits(const int raw){fixedPoint = raw;}

/**
 * @brief announce: dispaly message .
 * @details: display text message to stdout .
 * @param [in] message: text to display !
 * @return nothing .
*/
void Fixed::announce(const std::string& message) const {std::cout << message << std::endl;}


