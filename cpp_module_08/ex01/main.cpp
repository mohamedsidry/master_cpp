#include <iostream>
#include "Span.hpp"
#include <vector>
#include <list>
#include <ctime>
#include <stdlib.h>

/**
 * @brief main - Entry point of program .
 * @return 0 on success or exit code .
*/

int main(void)
{
    srand(time(NULL));
    Span<std::vector<int> > arr(10);


    for (std::vector<int>::iterator it = arr.container().begin(); it != arr.container().end(); it++)
        arr.addNumber((rand() % 100) * (rand() % 2 == 0 ? -1 : 1));
    
    for (std::vector<int>::const_iterator it = arr.container().begin(); it != arr.container().end(); it++)
        std::cout << "value : " << *it << ",";
    
    try
    {
        unsigned int longspan  = arr.longestSpan();
        std::cout << "\033[1;35m" << "longest Span : " << longspan << "\033[0m" << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << "\033[1;31m" << "Error : " <<e.what() << "\033[0m" << std::endl;
    }

    Span<std::vector<int> > sp = Span<std::vector<int> >(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.longestSpan() << std::endl;
    return (0);
}

