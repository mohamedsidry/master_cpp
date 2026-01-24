#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


int main(void)
{
    // Triangle vertices
    Point a(-1.5f, -1.0f);
    Point b(2.0f, 1.5f);
    Point c(3.5f, -2.0f);
    
    std::cout << "Triangle: A(-1.5, -1.0), B(2.0, 1.5), C(3.5, -2.0)\n\n";
    
    // Test 1: Point clearly inside
    Point p1(1.0f, 0.0f);
    std::cout << "Test 1 - P(1.0, 0.0): ";
    if (bsp(a, b, c, p1))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    // Test 2: Point clearly outside
    Point p2(5.0f, 5.0f);
    std::cout << "Test 2 - P(5.0, 5.0): ";
    if (bsp(a, b, c, p2))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    // Test 3: Point on vertex A
    Point p3(-1.5f, -1.0f);
    std::cout << "Test 3 - P(-1.5, -1.0) [Vertex A]: ";
    if (bsp(a, b, c, p3))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    // Test 4: Point on edge AB (midpoint)
    Point p4(0.25f, 0.25f);
    std::cout << "Test 4 - P(0.25, 0.25) [On edge AB]: ";
    if (bsp(a, b, c, p4))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    // Test 5: Point near center
    Point p5(1.5f, -0.5f);
    std::cout << "Test 5 - P(1.5, -0.5): ";
    if (bsp(a, b, c, p5))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    // Test 6: Point just outside
    Point p6(-2.0f, -1.0f);
    std::cout << "Test 6 - P(-2.0, -1.0): ";
    if (bsp(a, b, c, p6))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    // Test 7: Point with decimals inside
    Point p7(0.75f, -0.25f);
    std::cout << "Test 7 - P(0.75, -0.25): ";
    if (bsp(a, b, c, p7))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    // Test 8: Point close to edge but inside
    Point p8(1.8f, 0.3f);
    std::cout << "Test 8 - P(1.8, 0.3): ";
    if (bsp(a, b, c, p8))
        std::cout << "INSIDE ✓" << std::endl;
    else
        std::cout << "OUTSIDE ✗" << std::endl;
    
    return 0;
}
