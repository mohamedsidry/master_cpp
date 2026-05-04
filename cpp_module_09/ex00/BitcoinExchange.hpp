#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <utility>
#include <map>
#include <exception>
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
/**
 * @brief BitcoinExchange - class that store record of bitcoin exchange_rate per date) in a sorted map .
 * @details BitcoinExchange takes a file database contain records of bitcoin store it so that later we can give evaluate the value of bitcoin base on an other file given to the function . 
 * 
*/
class BitcoinExchange
{
    private:
        std::string database_src_;
        std::map<unsigned long, double> database_;
        void init(void);
        void load(std::ifstream&);
        void process(std::ifstream &) const;

    public:
        static std::string DEFAULT_DB;
        BitcoinExchange();
        BitcoinExchange(const char *);
        BitcoinExchange(const std::string&);
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
        ~BitcoinExchange();
        void evaluate(const char *file) const;
        void evaluate(const std::string& file) const;
        static std::string serialize(const std::pair<unsigned long, double>& pval, const std::string& sep);
        static std::pair<unsigned long, double> deserialize(const std::string& sval, const std::string& sep);
        static std::string serialize_date(unsigned long date) ;
        static unsigned long deserialize_date(const std::string& date);
        static std::string serialize_value(double);
        static double deserialize_value(const std::string&);
        static bool is_valid_date(const std::string& );
        static bool is_valid_value(const std::string& );
        static std::string trim(const std::string& line);
        class FileException : public std::exception
        {
            public:
                virtual const char * what(void) const throw();
        };
        class NegativeNumberException : public std::exception
        {
            public:
                const char * what(void) const throw();
        };
        class BadInputException : public std::exception
        {
            public:
                const char * what(void) const throw();
        };
        class TooLargeNumberException : public std::exception
        {
            public:
                const char * what(void) const throw();
        };
        class EmptyDatabaseException : public std::exception
        {
            public:
                const char * what(void) const throw();
        };
        class BadHeaderException : public std::exception
        {
            public:
                const char * what(void) const throw();
        };
};

#endif // BITCOINEXCHANGE_HPP

