#include <iostream>
#include "Fixed.hpp"



int main(void)
{
    Fixed fxx;
    Fixed fx2;

    fx2 = fxx;
    std::cout << "value : " << fxx.getRawBits() << std::endl;
    std::cout << "hello world !!!" << std::endl;
    return (0);
}
