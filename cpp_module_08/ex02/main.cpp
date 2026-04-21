#include <iostream>
#include "MutantStack.hpp"



/**
 * @brief main - Entry point of program .
 * @return 0 on success or exit status .
*/



int main(void)
{
    MutantStack<int> mstack;

    mstack.push(42);
    mstack.push(512);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    std::cout << mstack.size() << std::endl;



    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    it++;
    it--;
    while (it != ite)
    {
        std::cout << "value is : " << *it << std::endl;
        it++;
    }
    std::stack<int> s(mstack);
    while (s.size())
    {
        std::cout << " --- value is : " << s.top() << std::endl;
        s.pop();
    }
    MutantStack<int> s2 = mstack;

    MutantStack<int>::iterator it2 = mstack.begin();
    MutantStack<int>::iterator ite2 = mstack.end();
    it2++;
    it2--;
    while (it2 != ite2)
    {
        std::cout << "value is : " << *it2 << std::endl;
        it2++;
    }
    return 0;
}

