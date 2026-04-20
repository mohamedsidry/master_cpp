#include <iostream>
#include "Span.hpp"
#include <vector>
#include <stdlib.h>

/**
 * @brief main - Entry point of program .
 * @return 0 on success or exit code .
*/

void randomize(int & ref);

int main(void)
{
    srand(time(NULL));
    
    {
        std::clog << "\033[1;33m" << "Test 0 : " << "\033[0m" << "Empty Span ." << "\033[0m" << std::endl;
        Span empty;
        try
        {
            empty.addNumber(-42);
            std::clog << "\033[1;36m" << "Log : " << "Number was added to empty Span . !!!" << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[1;31m" << "Error : " <<e.what() << "\033[0m" << std::endl;
        }

        try
        {
            unsigned int shortspan = empty.shortestSpan();
            std::clog << "\033[1;36m" << "Log : " << "shortest Span is " << shortspan << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[1;31m" << "Error : " <<e.what() << "\033[0m" << std::endl;
        }

        try
        {
            unsigned int longspan = empty.longestSpan();
            std::clog << "\033[1;36m" << "Log : " << "longest Span is " << longspan << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[1;31m" << "Error : " <<e.what() << "\033[0m" << std::endl;
        } 
    }
    {
        std::clog << "\033[1;33m" << "Test 1 : " << "\033[0m" << "One element Span ." << "\033[0m" << std::endl;
        Span one_element(1);
        try
        {
            one_element.addNumber(-42);
            std::clog << "\033[1;36m" << "Log : " << "Number was added to Span . !!!" << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[1;31m" << "Error : " <<e.what() << "\033[0m" << std::endl;
        }

        try
        {
            unsigned int shortspan = one_element.shortestSpan();
            std::clog << "\033[1;36m" << "Log : " << "shortest Span is " << shortspan << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[1;31m" << "Error : " <<e.what() << "\033[0m" << std::endl;
        }

        try
        {
            unsigned int longspan = one_element.longestSpan();
            std::clog << "\033[1;36m" << "Log : " << "longest Span is " << longspan << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[1;31m" << "Error : " <<e.what() << "\033[0m" << std::endl;
        } 
    }
    {
        std::clog << "\033[1;33m" << "Test 2 : " << "\033[0m" << "Subject test ." << "\033[0m" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "\033[1;34m" << "Output : " << "shortest Span is " << sp.shortestSpan() << "\033[0m" << std::endl;
        std::cout << "\033[1;35m" << "Output : " << "longest Span is " << sp.longestSpan() << "\033[0m" << std::endl;
    }
    {
        std::clog << "\033[1;33m" << "Test 3 : " << "\033[0m" << "Random 256 ." << "\033[0m" << std::endl;
        std::vector<int> tmp(512);
        Span span(256);
        std::for_each(tmp.begin(), tmp.end(), randomize);
        span.addNumber(tmp.begin(), tmp.begin() + 256);
        for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
            std::clog << (it == tmp.begin() ? "[" : " ,") << *it << (it + 1 == tmp.end() ? "]\n" : "");
        std::cout << "\033[1;34m" << "Output : " << "shortest Span is " << span.shortestSpan() << "\033[0m" << std::endl;
        std::cout << "\033[1;35m" << "Output : " << "longest Span is " << span.longestSpan() << "\033[0m" << std::endl;
    }

    {
        std::clog << "\033[1;33m" << "Test 4 : " << "\033[0m" << "Random 100k ." << "\033[0m" << std::endl;
        std::vector<int> tmp(100000);
        Span span(100000);
        std::for_each(tmp.begin(), tmp.end(), randomize);
        span.addNumber(tmp.begin(), tmp.end());
        std::cout << "\033[1;34m" << "Output : " << "shortest Span is " << span.shortestSpan() << "\033[0m" << std::endl;
        std::cout << "\033[1;35m" << "Output : " << "longest Span is " << span.longestSpan() << "\033[0m" << std::endl;
    }

    {
        std::clog << "\033[1;33m" << "Test 5 : " << "\033[0m" << "Random 1M ." << "\033[0m" << std::endl;
        std::vector<int> tmp(1000000);
        Span span(1000000);
        std::for_each(tmp.begin(), tmp.end(), randomize);
        span.addNumber(tmp.begin(), tmp.end());
        std::cout << "\033[1;34m" << "Output : " << "shortest Span is " << span.shortestSpan() << "\033[0m" << std::endl;
        std::cout << "\033[1;35m" << "Output : " << "longest Span is " << span.longestSpan() << "\033[0m" << std::endl;
    }
    return (0);
}


void randomize(int & ref)
{
    ref = rand() % 1000000;
}

