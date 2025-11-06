#include <iostream>
#include "Fixed.hpp"



int main(void)
{
    Fixed const a( 1.0f );
    std::cout << "a is " << a << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    return 0;
}
