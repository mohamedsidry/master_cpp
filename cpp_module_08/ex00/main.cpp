
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include "easyfind.hpp"

/**
 * @brief main - Entry point of program .
 * @return 0 on success or exit code .
*/
int main(void)
{

    srand(time(NULL));

    {
        std::cout << std::endl;
        std::vector<int> vecRands(32);
        std::clog << "\033[1;33m" << "Test 0 : " << "\033[0m" << "Vector container ." << "\033[0m" << std::endl;
        for (std::vector<int>::iterator it = vecRands.begin(); it != vecRands.end(); it++)
           *it = rand() % 100;
        for (std::vector<int>::const_iterator it = vecRands.begin(); it != vecRands.end(); it++)
            std::cout << *it <<  (it + 1 != vecRands.end() ? ", " : "\n");
        try
        {
            int target = 42;
            std::cout << "\033[1;34m" << "Search for : " << "\033[0m" << target << std::endl;
            std::vector<int>::value_type it = easyfind<std::vector<int> >(vecRands,target);
            std::cout << "\033[1;32m" << "Easy find : " << "\033[0m" << it << std::endl;
        }catch(const std::runtime_error& e)
        {
            std:: cerr << "\033[1;31m" << "Error : " << "\033[0m" << e.what() << std::endl;
        }
        std::cout << "\n\n";
    }

    {
        std::array<int, 32> arrRands;
        std::clog << "\033[1;33m" << "Test 1 : " << "\033[0m" << "Array container ." << "\033[0m" << std::endl;
        for (std::array<int, 32>::iterator it = arrRands.begin(); it != arrRands.end(); it++)
            *it = rand() % 100;
        for (std::array<int, 32>::const_iterator it = arrRands.begin(); it != arrRands.end(); it++)
            std::cout << *it <<  (it + 1 != arrRands.end() ? ", " : "\n");
        try
        {
            int target = 42;
            std::cout << "\033[1;34m" << "Search for : " << "\033[0m" << target << std::endl;
            std::array<int, 32>::value_type it = easyfind<std::array<int, 32> >(arrRands,target);
            std::cout << "\033[1;32m" << "Easy find : " << "\033[0m" << it << std::endl;
        }catch(const std::runtime_error& e)
        {
            std:: cerr << "\033[1;31m" << "Error : " << "\033[0m" << e.what() << std::endl;
        }
        std::cout << "\n\n";
    }

    {

        std::clog << "\033[1;33m" << "Test 2 : " << "\033[0m" << "List container update first occurrence ." << "\033[0m" << std::endl;
        std::list<int> lst;
        lst.push_back(rand() % 1000);
        lst.push_back(rand() % 1000);
        lst.push_back(rand() % 1000);
        lst.push_back(rand() % 1000);
        lst.push_back(rand() % 1000);
        for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
        {
            std::cout << *it <<  (lst.end() != ++it ? ", " : "\n");
            --it;
        }
        try
        {
            int target = 42;
            std::cout << "\033[1;34m" << "Search for : " << "\033[0m" << target << std::endl;
            std::list<int>::value_type& it = easyfind<std::list<int> >(lst,target);
            std::cout << "\033[1;32m" << "Easy find : " << "\033[0m" << it << std::endl;
        }catch(const std::runtime_error& e)
        {
            std:: cerr << "\033[1;31m" << "Error : " << "\033[0m" << e.what() << std::endl;
        }
        std::cout << "\n\n";
    }

    {

        std::clog << "\033[1;33m" << "Test 3 : " << "\033[0m" << "Vector container update first occurrence ." << "\033[0m" << std::endl;
        std::vector<int> vecRands(32);

        for (std::vector<int>::iterator it = vecRands.begin(); it != vecRands.end(); it++)
           *it = rand() % 100;
        vecRands[16] = 42;
        for (std::vector<int>::const_iterator it = vecRands.begin(); it != vecRands.end(); it++)
            std::cout << *it <<  (it + 1 != vecRands.end() ? ", " : "\n");
        try
        {
            int target = 42;
            std::cout << "\033[1;34m" << "Search for : " << "\033[0m" << target << std::endl;
            std::vector<int>::value_type& it = easyfind<std::vector<int> >(vecRands,target);
            it = 1337;
            std::cout << "\033[1;32m" << "Easy find : " << "\033[0m" << target << std::endl;
            std::cout << "\033[1;35m" << "Replaced with : " << "\033[0m" << it << std::endl;
        }catch(const std::runtime_error& e)
        {
            std:: cerr << "\033[1;31m" << "Error : " << "\033[0m" << e.what() << std::endl;
        }
        for (std::vector<int>::const_iterator it = vecRands.begin(); it != vecRands.end(); it++)
            std::cout << *it <<  (it + 1 != vecRands.end() ? ", " : "\n");
        
        std::cout << std::endl;
    }

    return (0);
}
