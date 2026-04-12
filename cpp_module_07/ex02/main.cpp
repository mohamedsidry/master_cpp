#include <iostream>
#include "Array.hpp"
#include "test.hpp"



const char *RED = "\033[1;31m";
const char *GREEN = "\033[1;32m";
const char *YELLOW = "\033[1;33m";
const char *PURPLE = "\033[1;34m";
const char *RESET = "\033[0m";




void ll(void);
void header(const char *color, const char *title);
template<typename T>
void colored(std::ostream& os, const char *color, T& item);

void string_on_tests(void);
void int_on_tests(void);
void float_on_tests(void);
void double_on_tests(void);
void random_test(void);

int main(void)
{
    string_on_tests();
    int_on_tests();
    float_on_tests();
    double_on_tests();
    random_test();

    //atexit(ll);
    return (0);
}




void randomize(unsigned int & ref)
{
    ref = rand() % 100;
}


template<typename T>
void printItem(T& ref)
{
    std::cout << ref << std::endl;
}

void random_test(void)
{
    srand(time(NULL));
    Array<unsigned int> randoms(100);
    //randoms.iter(randomize);
    ForEach<unsigned int, void (*)(unsigned int&)> obj; obj(randoms, randoms.size(), randomize);
    obj(randoms,randoms.size(), [](unsigned int &it){ std::cout << GREEN << it << RESET << ", ";});
    //randoms.iter(printItem<unsigned int&>);
    //::ForEach(randoms, randoms.size(), randomize);
}





void string_on_tests(void)
{
    header(YELLOW, "Teset : array of strings");
    Array<std::string> arr0;
    std::cout << "arr0 : " << arr0 << std::endl;
    const Array<std::string> arr1(10);
    std::cout << "arr1 : " << arr1 << std::endl;
    arr0 = arr1;
    arr0[0] = "first world";
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr1 : " << arr1 << std::endl;
    Array<std::string> arr2(arr0);
    arr2[9] = "last word";
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr2 : " << arr2 << std::endl;

    try
    {
        arr0[10] = "watch out what's ganna happen !";
    }catch(const Array<std::string>::ExceptionOutOfBounds& e)
    {
        colored(std::cerr, RED,"Error : ");
        std::cerr << e.what() << std::endl;
    }
}

void int_on_tests(void)
{
    header(YELLOW, "Teset : array of ints");
    Array<int> arr0;
    std::cout << "arr0 : " << arr0 << std::endl;
    const Array<int> arr1(10);
    std::cout << "arr1 : " << arr1 << std::endl;
    arr0 = arr1;
    arr0[0] = 1337;
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr1 : " << arr1 << std::endl;
    Array<int> arr2(arr0);
    arr2[9] = 42;
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr2 : " << arr2 << std::endl;

    try
    {
        arr0[10] = -42;
    }catch(const Array<int>::ExceptionOutOfBounds& e)
    {
        colored(std::cerr, RED,"Error : ");
        std::cerr << e.what() << std::endl;
    }
}

void float_on_tests(void)
{
    header(YELLOW, "Teset : array of floats");
    Array<float> arr0;
    std::cout << "arr0 : " << arr0 << std::endl;
    const Array<float> arr1(10);
    std::cout << "arr1 : " << arr1 << std::endl;
    arr0 = arr1;
    arr0[0] = 0.5;
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr1 : " << arr1 << std::endl;
    Array<float> arr2(arr0);
    arr2[9] = 42.42;
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr2 : " << arr2 << std::endl;
    try
    {
        arr0[10] = -42;
    }catch(const Array<float>::ExceptionOutOfBounds& e)
    {
        colored(std::cerr, RED,"Error : ");
        std::cerr << e.what() << std::endl;
    }
}

void double_on_tests(void)
{
    header(YELLOW, "Teset : array of doubles");
    Array<double> arr0;
    std::cout << "arr0 : " << arr0 << std::endl;
    const Array<double> arr1(10);
    std::cout << "arr1 : " << arr1 << std::endl;
    arr0 = arr1;
    arr0[0] = 0.5;
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr1 : " << arr1 << std::endl;
    Array<double> arr2(arr0);
    arr2[9] = 42.42;
    std::cout << "arr0 : " << arr0 << std::endl;
    std::cout << "arr2 : " << arr2 << std::endl;
    try
    {
        arr0[10] = -42;
    }catch(const Array<double>::ExceptionOutOfBounds& e)
    {
        colored(std::cerr, RED,"Error : ");
        std::cerr << e.what() << std::endl;
    }
}



void ll(void)
{
    system("leaks -q executable");
}


void header(const char *color, const char *title)
{
    std::cout << color << title << RESET << std::endl;
}

template<typename T>
void colored(std::ostream& os, const char *color, T& item)
{
    os << color << item << RESET;
}