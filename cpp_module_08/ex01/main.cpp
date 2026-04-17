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
    Span<std::vector<int> > arr(100);


    for (std::vector<int>::iterator it = arr.container().begin(); it != arr.container().end(); it++)
        arr.addNumber(rand() % 100);

    for (std::vector<int>::const_iterator it = arr.container().begin(); it != arr.container().end(); it++)
        std::cout << "value : " << *it << std::endl;
    
    return (0);
}

