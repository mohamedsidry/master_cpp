#ifndef _FORMATTER_HPP
#define _FORMATTER_HPP

#include "../../includes/main.hpp"

class Formatter
{
    public:
        static std::string  formatField(const std::string& str, size_t max_width, t_textAlign align);
        static int          toInt(const std::string& str);
        static std::string  toString(int value);

};

#endif // _FORMATTER_HPP
