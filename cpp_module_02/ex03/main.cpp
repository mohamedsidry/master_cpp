#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


int main(void)
{
    Point a(-1, -1);
    Point b(1, 1);
    Point c(4, -2);
    Point p(0.5f,0.5f);

    if (p.bsp(a, b, c, p))
        std::cout << "it is in !" << std::endl; 
    else
        std::cout << "it is out !" << std::endl; 
    
    Point::drawPointArea(a, b, c, p);
    return 0;
}
