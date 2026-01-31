#ifndef REPLACE_HPP

#define REPLACE_HPP
#include <string>

class Replace
{
    public:
        Replace(); // delete .
        ~Replace(); // delete .
        Replace(const Replace&); // delete .
        Replace& operator=(const Replace&); // delete .
        static void fileReplace(const std::string& file, const std::string& target, const std::string& repace);
        static void strReplace(std::string&str, const std::string& target, const std::string& replace);
};

#endif //REPLACE_HPP
