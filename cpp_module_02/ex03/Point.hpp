#ifndef POINT_HPP

#define POINT_HPP
#include "Fixed.hpp"
#include <fstream>


class Point
{

    private:

        const Fixed x;
        const Fixed y;
        Point& operator=(const Point& other);

    public:
        Point();
        Point(const float fp1, const float fp2);
        Point(const Point& fp);
        Point(const Fixed& x, const Fixed& y);
        ~Point();

        friend bool operator==(const Point& point1, const Point& point2);
        const Fixed& getX(void) const;
        const Fixed& getY(void) const;
        bool bsp( Point const a, Point const b, Point const c, Point const point);
        static Fixed area(const Point& pointA, const Point& pointB, const Point& pointC);
        static void drawArea(const Point& pointA, const Point& pointB, const Point& pointC);
        static void drawPointArea(const Point& pointA, const Point& pointB, const Point& pointC, const Point& point);


};


#endif // POINT_HPP
