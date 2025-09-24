#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>

class Validator
{
    private:
        Validator(); //delete
        ~Validator(); //delete
        Validator(const Validator&); //delete
        Validator& operator=(const Validator&); //delete
        static const int _paramCount = 3;
    public:
        static void validateParamCount(int argc);
        static bool isValidParamCount(int argc);
        static bool isValidTargetStr(const char *str);
        static bool isValidIO(const char *file);
        template <typename T>
        static void validateFileStream(const std::string& file)
        {
            T fstr;
            fstr.exceptions(T::failbit | T::badbit);
            try
            {
                fstr.open(file.c_str());
            }
            catch(const std::ios_base::failure& e)
            {
                throw std::runtime_error("Failed to open file:" + file);
            }
        }
        static bool validate(int argc, char *argv[]);
};


#endif // VALIDATOR.HPP
