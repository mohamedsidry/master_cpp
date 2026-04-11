#include <iostream>
#include "iter.hpp"



template <typename T>
void colorful(const T& ele);


void put_fraction(const double &val);
void put_fraction(const float &val);
void roundf(float& note);
void roundd(double& note);
void pow_two(float& item);
void pow_two(double& item);
void pow_two(int& item);
/**
 * @brief main - entry point of program .
 * @return 0 on success exit code on failure .
*/
int main(void)
{
    srand(time(NULL));
    {
        const std::string quotes[] = {
        "Programs must be written for people to read, and only incidentally for machines to execute.",
        "Talk is cheap. Show me the code.",
        "First, solve the problem. Then, write the code.",
        "Any fool can write code that a computer can understand. Good programmers write code that humans can understand.",
        "Experience is the name everyone gives to their mistakes.",
        "Code is like humor. When you have to explain it, it's bad.",
        "Fix the cause, not the symptom.",
        "Before software can be reusable it first has to be usable.",
        "Make it work, make it right, make it fast.",
        "Simplicity is the soul of efficiency."
        };
        ::iter(quotes, sizeof(quotes) / sizeof(quotes[0]), colorful);
    }
    {
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ::iter(arr, sizeof(arr) / sizeof(arr[0]), pow_two);
        ::iter(arr, sizeof(arr) / sizeof(arr[0]), ::colorful);
    }
    {
        const double notes [] = {7.75, 11.25, 10.25, 16.51, 13.50, 14, 16.45, 15.51, 17.15};
        
        ::iter(notes, sizeof(notes) / sizeof(notes[0]), ::put_fraction);
        std::cout << std::endl;
    }
    {
        float notes [] = {7.75, 11.25, 10.25, 16.51, 13.50, 14, 16.45, 15.51, 17.15};
        
        ::iter(notes, sizeof(notes)/ sizeof(notes[0]), ::roundf);
        ::iter(notes, sizeof(notes) / sizeof(notes[0]), ::colorful);
    }
    return (0);
}


/**
 * @brief colorfull - display given input to standard output with random color .
 * @param [in] ele element to display its info in color .
*/
template <typename T>
void colorful(const T& ele)
{
    std::string colors [] = { "\033[1;30m", "\033[1;31m", "\033[1;32m", "\033[1;33m", "\033[1;34m", "\033[1;35m", "\033[1;36m", "\033[1;37m"};
    std::string reset = "\033[0m";
    int index = rand() % (sizeof(colors) / sizeof(colors[0]));
    std::cout << colors[index] << ele <<  reset << std::endl;
}



/**
 * @brief round_it - rounds input to the closeest value .
 * @param [in] note value to be rouned .
*/
void roundf(float& note)
{
    int val = static_cast<int>(note);
    note = (note - val > 0.5) ? val + 1 : val;
}

/**
 * @brief round_it - rounds input to the closeest value .
 * @param [in] note value to be rouned .
*/
void roundd(double& note)
{
    int val = static_cast<int>(note);
    note = (note - val > 0.5) ? val + 1 : val;
}

/**
 * @brief put_fraction - prints fraction part of number to stdout .
 * @param [in] val number . 
*/
void put_fraction(const double &val)
{
    std::cout << val - static_cast<int>(val) << " ";
}

/**
 * @brief put_fraction - prints fraction part of number to stdout .
 * @param [in] val number . 
*/
void put_fraction(const float &val)
{
    std::cout << val - static_cast<int>(val) << " ";
}

/**
 * @brief colorfull - display given input to standard output with random color .
 * @param [in] ele element to display its info in color .
*/
void pow_two(float& item)
{
    item *= item;
}


/**
 * @brief colorfull - display given input to standard output with random color .
 * @param [in] ele element to display its info in color .
*/
void pow_two(double& item)
{
    item *= item;
}

/**
 * @brief colorfull - display given input to standard output with random color .
 * @param [in] ele element to display its info in color .
*/
void pow_two(int& item)
{
    item *= item;
}