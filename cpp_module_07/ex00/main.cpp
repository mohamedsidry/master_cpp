#include "whatever.hpp"
#include <iostream>



/**
 * @brief main - entry point of program .
 * @return 0 on success and exit code on failure .
*/
int main(void)
{
    {
        std::cout << "\033[1;33m TEST :  Swaps the values of two given parameters .\033[0m" << std::endl;
        {
            std::cout << "\033[1;34m INT Type:\033[0m" << std::endl;
            int n1337 = 1337;
            int n42 = 42;
            std::cout << " BEFORE : " <<"number 1337 = " << n1337 << " , " << "number 42 = " <<  n42 << std::endl;
            ::swap(n1337, n42);
            std::cout << " AFTER  : " <<"number 1337 = " << n1337 << " , " << "number 42 = " <<  n42 << std::endl;
        }

        {
            std::cout << "\033[1;34m CHAR Type:\033[0m" << std::endl;
            char A = 'A';
            char Z = 'Z';
            std::cout << " BEFORE : " <<"Char A = " << A << " , " << "Char Z = " <<  Z << std::endl;
            ::swap(A, Z);
            std::cout << " AFTER  : " <<"Char A = " << A << " , " << "Char Z = " <<  Z << std::endl;
        }

        {
            int a = 2;
            int b = 3;
            ::swap( a, b );
            std::cout << "a = " << a << ", b = " << b << std::endl;
            std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
            std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
            std::string c = "chaine1";
            std::string d = "chaine2";
            ::swap(c, d);
            std::cout << "c = " << c << ", d = " << d << std::endl;
            std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
            std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        }

    }

    


    return (0);
}


