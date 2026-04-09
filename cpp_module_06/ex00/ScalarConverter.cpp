#include "ScalarConverter.hpp"
#include <cmath>
#include <iomanip>

/**
 * @brief ScalarConverter::convert display given input in {char, int, float, double} forms if possible.
 * @param [in] input string to be convered .
*/
void ScalarConverter::convert(std::string const &input)
{
    e_type type = detect_type(input);

    if (type == OTHER_T)
        print_impossible();
    else if (type == PSEUDO_T)
        print_pseudo(input);
    else
    {
        double value;
        if (type == CHAR_T)
            value = static_cast<double>(input[0]);
        else
            value = std::strtod(input.c_str(), NULL);
        print_char(value);
        print_int(value);
        print_float(value);
        print_double(value);
    }
}

/**
 * @brief ScalarConverter::detect_type detect the type of given input .
 * @param [in] value input string .
 * @return type of given input .
*/
e_type ScalarConverter::detect_type(std::string const & value)
{
    if (is_pseudo(value))
        return (PSEUDO_T);
    else if (is_char(value))
        return (CHAR_T);
    else if(is_int(value))
        return (INT_T);
    else if (is_float(value))
        return (FLOAT_T);
    else if (is_double(value))
        return (DOUBLE_T);
    return (OTHER_T);
}

/**
 * @brief ScalarConverter::print_impossible display all impossible . 
*/
void ScalarConverter::print_impossible(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

/**
 * @brief ScalarConverter::is_pseudo check if input is a pseudo literal .
 * @param [in] input string to check .
 * @return true or false .
*/
bool ScalarConverter::is_pseudo(std::string const & input)
{
    const std::string lits[] = {"nan", "nanf", "-inf", "+inf", "-inff", "+inff"};
    for (const std::string* el = std::begin(lits); el != std::end(lits); el++)
    {
        if (input == *el)
            return (true);
    }
    return (false);
}

/**
 * @brief ScalarConverter::print_pseudo display pseudo literals .
 * @param [in] input pseudo literal .
*/
void ScalarConverter::print_pseudo(std::string const & input)
{
    std::string tmp;

    if (input.find("inff", 0) == std::string::npos && input.find("nanf", 0) == std::string::npos)
        tmp = input;
    else
        tmp = input.substr(0, input.length() - 1);
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " <<  tmp <<  "f" << std::endl;
    std::cout << "double: " <<  tmp << std::endl;
}

/**
 * @brief ScalarConverter::is_char check if input is a char .
 * @param [in] input string to check .
 * @return true or false .
*/
bool ScalarConverter::is_char(std::string const & input)
{
    return (input.length() == 1 && !isdigit(input[0]) && std::isprint(input[0]));
}

/**
 * @brief ScalarConverter::print_char display char value .
 * @param [in] input value of char in double format .
*/
void ScalarConverter::print_char(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value > 127 || value < 0)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

/**
 * @brief ScalarConverter::is_int check if input is a int .
 * @param [in] input string to check .
 * @return true or false .
*/
bool ScalarConverter::is_int(std::string const & input)
{
    int idx = 0;
    if (input[idx] == '+' || input[idx] == '-')
        idx++;
    if (!input[idx])
        return (false);
    for (; input[idx]; idx++)
        if (!isdigit(input[idx]))
            return (false);
    return (true);
}

/**
 * @brief ScalarConverter::print_int display int value .
 * @param [in] input value of int in double format .
*/
void ScalarConverter::print_int(double value)
{
    std::cout << "int: ";

    if (value > INT32_MAX || value < INT32_MIN || std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

/**
 * @brief ScalarConverter::is_double check if input is a double .
 * @param [in] input string to check .
 * @return true or false .
*/
bool ScalarConverter::is_double(std::string const & input)
{
    int idx = 0;
    int dot = 0;
    int digit = 0;

    if (input[0] == '+' || input[0] == '-')
        idx++;
    
    for (; input[idx]; idx++)
    {
        if (input[idx] == '.')
            dot++;
        else if (!isdigit(input[idx]))
            return (false);
        else
            digit++;
    }
    return (dot == 1 && digit > 0);
}

/**
 * @brief ScalarConverter::print_double display double value .
 * @param [in] input value in double format .
*/
void ScalarConverter::print_double(double value)
{
    std::cout << "double: ";
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << value << std::endl;
        return ;
    }
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

/**
 * @brief ScalarConverter::is_float check if input is a float .
 * @param [in] input string to check .
 * @return true or false .
*/
bool ScalarConverter::is_float(std::string const & input)
{
    if (input[input.length() - 1] != 'f')
        return (false);
    return (is_double(input.substr(0, input.length() - 1)));
}

/**
 * @brief ScalarConverter::print_float display float value .
 * @param [in] input value in double format .
*/
void ScalarConverter::print_float(double value)
{
    std::cout << "float: ";
    if (isinf(value) || isnan(value))
    {
        std::cout << static_cast<float>(value) << "f" << std::endl;
        return ;
    }
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

