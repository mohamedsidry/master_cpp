#include "Point.hpp"



/**
 * @brief Point: default constructor .
 * @details: set attributes to default values .
 * @param no_params
 * @return nothing !
*/
Point::Point(): x(Fixed()), y(Fixed()){}

/**
 * @brief Point: constructor that takes a float .
 * @details: set fixedPoint attributes to nbr .
 * @param [in] fp1 x coordinate !
 * @param [in] fp2 y coordinate !
 * @return nothing !
*/
Point::Point(const float fp1, const float fp2):x(fp1), y(fp2){}

/**
 * @brief Point: copy constructor .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return nothing !
*/
Point::Point(const Point& other):x(other.x), y(other.y){}

/**
 * @brief Point: constructor that takes a float .
 * @details: set fixedPoint attributes to nbr .
 * @param [in] x x coordinate !
 * @param [in] y y coordinate !
 * @return nothing !
*/
Point::Point(const Fixed& x, const Fixed& y):x(x),y(y){}

/**
 * @brief operator=: copy assignment .
 * @details : this make is bull*hit .
 * @param [in] other : this is bull*hit .
 * @return nothing !
*/
const Point& Point::operator=(const Point&)
{
    return *this;
}

/**
 * @brief ~Point: default destructor .
 * @details: release the resourses .
 * @param no_params
 * @return nothing !
*/
Point::~Point(){}





/**
 * @brief getX: get x value .
 * @param no_params
 * @return the value in fixedPoint attribute .
*/
const Fixed& Point::getX(void) const {return this->x;}

/**
 * @brief getX: get y value .
 * @param no_params
 * @return the value in fixedPoint attribute .
*/
const Fixed& Point::getY(void) const {return this->y;}
