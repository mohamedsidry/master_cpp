#include "Point.hpp"




Point::Point(): x(Fixed()), y(Fixed()){}

Point::Point(const float fp1, const float fp2):x(fp1), y(fp2){}

Point::Point(const Point& other):x(other.x), y(other.y){}

Point::Point(const Fixed& x, const Fixed& y):x(x),y(y){}

Point::~Point(){}



bool operator==(const Point& point1, const Point& point2)
{
    return (point1.getX()== point2.getX() &&point1.getY()== point2.getY());
}



const Fixed& Point::getX(void) const {return this->x;}

const Fixed& Point::getY(void) const {return this->y;}

typedef Point Vector;
typedef Fixed Area;

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    Area total = area(a, b, c);

    Area area1, area2, area3;
    area1 = area(a, b, point);
    area2 = area(a, c, point);
    area3 = area(b, c, point);
    
    //return ((total == (area1 + area2 + area3)) && area1 * area2 * area3 != 0);
    return(total == (area1 + area2 + area3));
}

Area Point::area(const Point& pointA, const Point& pointB, const Point& pointC)
{
    Area area;
    Vector AB(pointB.getX() - pointA.getX(), pointB.getY() - pointA.getY());
    Vector AC(pointC.getX() - pointA.getX(), pointC.getY() - pointA.getY());
    area = AB.getX() * AC.getY() - AB.getY() * AC.getX();
    if (area < 0)
        area = area * -1;
    if (area == 0)
        return (0);
    return (area / 2);
}



void Point::drawArea(const Point& pointA, const Point& pointB, const Point& pointC)
{
    Fixed minX, minY, maxX, maxY;

    minX = Fixed::min(pointA.getX(), pointB.getX());
    minX = Fixed::min(minX, pointC.getX());
    maxX = Fixed::max(pointA.getX(), pointB.getX());
    maxX = Fixed::max(maxX, pointC.getX());
    minY = Fixed::min(pointA.getY(), pointB.getY());
    minY = Fixed::min(minY, pointC.getY());
    maxY = Fixed::max(pointA.getY(), pointB.getY());
    maxY = Fixed::max(maxY, pointC.getY());

    std::ofstream file("triangle.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open output file.\n";
        return;
    }

    for (Fixed y = maxY; y >= minY; y--)
    {
        for (Fixed x = minX; x <= maxX; x++)
        {
            Point p(x , y);
            if (p == pointA)
                file << "A";
            else if (p == pointB)
                file << "B";
            else if (p == pointC)
                file << "C";
            else if (p.bsp(pointA, pointB, pointC, p))
                file << "#";
            else
                file << ".";
        }
        file << std::endl;
    }

}



void Point::drawPointArea(const Point& pointA, const Point& pointB, const Point& pointC,  const Point& point)
{
    Fixed minX, minY, maxX, maxY;

    minX = Fixed::min(pointA.getX(), pointB.getX());
    minX = Fixed::min(minX, pointC.getX());
    maxX = Fixed::max(pointA.getX(), pointB.getX());
    maxX = Fixed::max(maxX, pointC.getX());
    minY = Fixed::min(pointA.getY(), pointB.getY());
    minY = Fixed::min(minY, pointC.getY());
    maxY = Fixed::max(pointA.getY(), pointB.getY());
    maxY = Fixed::max(maxY, pointC.getY());

    std::ofstream file("triangle.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open output file.\n";
        return;
    }

    for (Fixed y = maxY; y >= minY; y--)
    {
        for (Fixed x = minX; x <= maxX; x++)
        {
            Point p(x , y);
            if (p == pointA)
                file << "A";
            else if (p == pointB)
                file << "B";
            else if (p == pointC)
                file << "C";
            else if (p == point)
                file << "P";
            else if (p.bsp(pointA, pointB, pointC, p))
                file << "#";
            else
                file << ".";
        }
        file << std::endl;
    }

}