#include "Formatter.hpp"

std::string Formatter::formatField(const std::string& str, size_t max_width, t_textAlign align)
{
    if (str.length() > max_width)
        return str.substr(0, max_width - 1) + ".";
    if (align == RIGHT)
        return std::string(max_width - str.length(), ' ') + str;
    if (align == LEFT)
        return str + std::string(max_width - str.length(), ' ');
    if (align == CENTER)
    {
        if (str.length() % 2 == 0)
            return std::string((max_width - str.length()) / 2, ' ') + str + std::string((max_width - str.length()) / 2, ' ');
        return std::string((max_width - str.length()) / 2, ' ') + str + std::string((max_width - str.length()) / 2 + 1, ' ');
    }
    return str;
}

int Formatter::toInt(const std::string& str)
{
    int sign;
    int idx;
    int result;

    idx = 0;
    result = 0;
    sign = 1;
    while(str[idx] == '-' || str[idx] == '+')
    {
        if (str[idx] == '-')
            sign *= -1;
    }
    while (isdigit(str[idx]))
    {
        result = result * 10 + (str[idx] - 48);
        idx++;
    }
    return (result * sign);
}


std::string Formatter::toString(int value)
{
    std::ostringstream oss;
    oss << value;
    std::string strvalue = oss.str();
    return (strvalue);
}
