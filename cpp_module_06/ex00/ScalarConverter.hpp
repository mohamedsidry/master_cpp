#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>


typedef enum enum_type
{
  CHAR_T,
  INT_T,
  FLOAT_T,
  DOUBLE_T,
  PSEUDO_T,
  OTHER_T
}   e_type;



class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & );
        ScalarConverter& operator=(ScalarConverter const &);
        ~ScalarConverter();
        
        static e_type detect_type(std::string const &ref);
        
        static bool is_char(std::string const&);
        static void print_char(double value);

        static bool is_int(std::string const &);
        static void print_int(double value);

        static bool is_float(std::string const &);
        static void print_float(double value);

        static bool is_double(std::string const &);
        static void print_double(double value);
        
        static bool is_pseudo(std::string const &);
        static void print_pseudo(std::string const &);

        static void print_impossible(void);
        
    public:
        static void convert(std::string const &value);
    
};



#endif // SCALARCONVERTER_HPP

