#include <iostream>
#include "ScalarConverter.hpp"

/**
 * @brief main - program entry point .
 * @return 0 on success exit code in failure.
*/
int main(int argc, char *argv[])
{
    std::string value;
    if (argc < 2)
    {
        std::cerr << "Error : Invalid arguments count ." << std::endl;
        return (1);
    }
    value = argv[1];
    ScalarConverter::convert(value);
    return (0);
}

