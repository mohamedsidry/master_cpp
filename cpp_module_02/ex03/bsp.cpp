
#include "Point.hpp"


/**
 * @brief bsp : check if point is inside of triangle defined by a,b,c vertices .
 * @details using cross product of the vectors we check current vector is in the same side .
 * @param [in] a : point with x and y coordinate .
 * @param [in] b : point with x and y coordinate .
 * @param [in] c : point with x and y coordinate .
 * @param [in] point : point with x and y coordinate to check if it's within triangle .
 * @return true if it is within that triangle of false if not , edges and vertex excluded .
*/

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross;
    Fixed cross_ref;
    Vector ab(b.getX() - a.getX(), b.getY() - a.getY());
    Vector bc(c.getX() - b.getX(), c.getY() - b.getY());
    Vector ca(a.getX() - c.getX(), a.getY() - c.getY());
    
    Vector tmp0(point.getX() - a.getX(), point.getY() - a.getY());
    cross = ab.getX() * tmp0.getY() -  tmp0.getX() * ab.getY();
    cross_ref = ab.getX() * (c.getY() - a.getY()) - (c.getX() - a.getX()) * ab.getY();
    if (cross * cross_ref <= 0)
        return false;
    
    Vector tmp1(point.getX() - b.getX(), point.getY() - b.getY());
    cross = bc.getX() * tmp1.getY() -  tmp1.getX() * bc.getY();
    cross_ref = bc.getX() * (a.getY() - b.getY()) - (a.getX() - b.getX()) * bc.getY();
    if (cross * cross_ref <= 0)
        return false;

    Vector tmp2(point.getX() - c.getX(), point.getY() - c.getY());
    cross = ca.getX() * tmp2.getY() -  tmp2.getX() * ca.getY();
    cross_ref = ca.getX() * (b.getY() - c.getY()) - (b.getX() - c.getX()) * ca.getY();
    if (cross * cross_ref <= 0)
        return false;
    return true;
}
