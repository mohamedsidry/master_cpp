#ifndef POINT_HPP

#define POINT_HPP
#include "Fixed.hpp"
#include <fstream>


class Point
{

    private:

        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float fp1, const float fp2);
        Point(const Point& fp);
        Point(const Fixed& x, const Fixed& y);
        ~Point();
        const Point& operator=(const Point& other);
        // GETTERS && SETTERS
        const Fixed& getX(void) const;
        const Fixed& getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
typedef Point Vector;


#endif // POINT_HPP
