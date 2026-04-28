#include <iostream>
#include "MutantStack.hpp"



/**
 * @brief main - Entry point of program .
 * @return 0 on success or exit status .
*/



void printint(int i)
{
    std::cout << i << " ";
}


int main(void)
{
    {
        std::clog << "\033[1;33m" << "Test 0 : " << "\033[0m" << "Default Stack ." << "\033[0m" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(4);
        mstack.push(8);
        mstack.push(16);
        mstack.push(32);
        mstack.push(64);
        mstack.push(128);
        std::for_each(mstack.begin(), mstack.end(), printint);
        std::cout << std::endl;
        std::cout << "Stack size : " << mstack.size() << std::endl;
    }

    {
        std::clog << "\033[1;33m" << "Test 1 : " << "\033[0m" << "Copy Stack ." << "\033[0m" << std::endl;
        MutantStack<int> stack1;
        stack1.push(1);
        stack1.push(2);
        stack1.push(4);
        MutantStack<int> stack2(stack1);
        std::for_each(stack2.begin(), stack2.end(), printint);
        std::cout << std::endl;
        std::cout << "Stack size : " << stack2.size() << std::endl;
    }

    {
        std::clog << "\033[1;33m" << "Test 2 : " << "\033[0m" << "Stack iterator ." << "\033[0m" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.pop();
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        it++;
        it--;
        while (it != ite)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Stack size : " << mstack.size() << std::endl;
    }

    {
        std::clog << "\033[1;33m" << "Test 3 : " << "\033[0m" << "Stack const iterator ." << "\033[0m" << std::endl;
        MutantStack<int> stack1;
        stack1.push(1);
        stack1.push(2);
        stack1.push(4);
        const MutantStack<int> stack2(stack1);
        MutantStack<int>::const_iterator it = stack2.cbegin();
        MutantStack<int>::const_iterator ite = stack2.cend();
        it++;
        it--;
        while (it != ite)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Stack size : " << stack2.size() << std::endl;
    }
    return 0;
}

