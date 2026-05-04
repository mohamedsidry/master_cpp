#include "BitcoinExchange.hpp"

std::string BitcoinExchange::DEFAULT_DB = "data.csv";

/**
 * @brief BitcoinExchange - default constructor.
*/
BitcoinExchange::BitcoinExchange()
:database_src_(BitcoinExchange::DEFAULT_DB)
{
    init();
}

/**
 * @brief BitcoinExchange - param constructor.
 * @param [in] path database file.
*/
BitcoinExchange::BitcoinExchange(const char *path)
:database_src_(path)
{
    init();
}

/**
 * @brief BitcoinExchange - param constructor.
 * @param [in] path database file.
*/
BitcoinExchange::BitcoinExchange(const std::string& path)
:database_src_(path)
{
    init();
}

/**
 * @brief BitcoinExchange - copy constructor.
 * @param [in] other object to copy from.
*/
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
:database_src_(other.database_src_), database_(other.database_)
{}

/**
 * @brief BitcoinExchange - copy asign constructor.
 * @param [in] other object to copy from.
 * @return object reference.
*/
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        database_src_ = other.database_src_;
        database_ = other.database_;
    }
    return *this;
}

/**
 * @brief BitcoinExchange - destructor.
*/
BitcoinExchange::~BitcoinExchange()
{}



/**
 * @brief init - prepare database file to be loaded .
 * @details it trys to open database file display error in case of failure.
 * 
 * @throws FileException when unable to open database file.
*/
void BitcoinExchange::init(void)
{
    std::ifstream ifs;
    ifs.open(database_src_, std::ifstream::in);
    if (ifs.fail())
        throw BitcoinExchange::FileException();
    load(ifs);
    ifs.close();
}

/**
 * @brief load - loads data from given file to map.
 * @param [in] ifs opened file stream.
 * @details it reads file content line by line validate and store it to database.
*/
void BitcoinExchange::load(std::ifstream& ifs)
{
    std::string buffer;
    std::pair<unsigned long, double> ele;
    size_t idx = 0;

    while (std::getline(ifs, buffer))
    {
        if (buffer.empty())
            continue;
        if (idx == 0)
        {
            if (trim(buffer) != "date,exchange_rate")
            {
                ifs.close();
                throw BitcoinExchange::BadHeaderException();
            }
            ++idx;
            continue;
        }
        try
        {
            ele = BitcoinExchange::deserialize(buffer, ",");
            database_[ele.first] = ele.second;
        } catch (const std::exception& e)
        {
            std::cerr << "Error : " << e.what() << buffer << std::endl;
        }
    } 
}

/**
 * @brief process - process data from given open file stream.
 * @param [in] ifs opened file stream.
 * @details it reads file content line by line validate and evaluate btc value.
*/
void BitcoinExchange::process(std::ifstream& ifs) const 
{
    std::string buffer;
    std::pair<unsigned long, double> current;
    size_t idx = 0;

    while (std::getline(ifs, buffer))
    {
        if (buffer.empty())
            continue;
        if (idx == 0)
        {
            if (trim(buffer) != "date | value")
            {
                std::cerr << "Error : " << "bad header => " << buffer << std::endl;
                return;
            }
            ++idx;
            continue;
        }
        try
        {
            current = deserialize(buffer, "|");
            if (current.second  < 0)
                throw BitcoinExchange::NegativeNumberException();
            else if (current.second > 1000)
                throw BitcoinExchange::TooLargeNumberException();
            std::map<unsigned long, double>::const_iterator it = database_.lower_bound(current.first);
            if (it == database_.end() || it->first != current.first)
            {
                if (it == database_.begin())
                    throw BitcoinExchange::BadInputException();
                --it;
            }
            std::cout << serialize_date(current.first) << " => " << serialize_value(current.second * it->second)  << std::endl; 
        } catch(const BitcoinExchange::BadInputException& e)
        {
            std::cout << "Error : " << e.what() << buffer << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error : " << e.what() << std::endl;
        }
    };
}

/**
 * @brief evaluate - evaluate data of given file.
 * @param [in] ifs file contain data of format 'date | value'.
*/
void BitcoinExchange::evaluate(const char *file) const
{
    try
    {
        if (database_.empty())
            throw BitcoinExchange::EmptyDatabaseException();
        std::ifstream ifs;
        ifs.open(file, std::ifstream::in);
        if (ifs.fail())
            throw BitcoinExchange::FileException();
        process(ifs);
        ifs.close();
    } catch(const BitcoinExchange::FileException& e)
    {
        std::cout << "Error : " << e.what() << file << std::endl;
    }
     catch(const BitcoinExchange::EmptyDatabaseException& e)
    {
        std::cout << "Error : " << e.what()<< std::endl;
    }
}

/**
 * @brief evaluate - evaluate data of given file.
 * @param [in] ifs file contain data of format 'date | value'.
*/
void BitcoinExchange::evaluate(const std::string& file) const
{
    evaluate(file.c_str());
}


// Static methods
/**
 * @brief deserialize - convert data from string to pair.
 * @param [in] str string with key and value and separator.
 * @param [in] sep separator between key and value.
 * @return pair of date and value.
 * @throw BadInputException.
*/
std::pair<unsigned long, double> BitcoinExchange::deserialize(const std::string& str, const std::string& sep)
{
    std::string date, exchange_rate;
    std::pair<unsigned long, double> ele;
    size_t pos;

    pos = str.find(sep);
    if (std::string::npos == pos)
        throw BitcoinExchange::BadInputException();
    std::string left  = trim(str.substr(0, pos));
    std::string right = trim(str.substr(pos + 1));
    ele.first = BitcoinExchange::deserialize_date(left);
    ele.second = BitcoinExchange::deserialize_value(right);
    return ele;
}

/**
 * @brief serialize - convert pair to string format.
 * @param [in] pval pair with date and value .
 * @param [in] sep separator between key and value.
 * @return string date+sep+value.
*/
std::string BitcoinExchange::serialize(const std::pair<unsigned long, double>& pval, const std::string& sep)
{
    return BitcoinExchange::serialize_date(pval.first) + sep + BitcoinExchange::serialize_value(pval.second);
}

/**
 * @brief deserialize_date - convert date from string to unsigned long format.
 * @param [in] date string date.
 * @return date.
 * @throw BadInputException.
*/
unsigned long BitcoinExchange::deserialize_date(const std::string& date)
{
    std::string yyyy, mm, dd;
    size_t pos1, pos2;

    if (!is_valid_date(date))
        throw BitcoinExchange::BadInputException();
    pos1 = date.find('-', 0);
    pos2 = date.find('-', pos1 + 1);
    if (std::string::npos == pos1 || std::string::npos == pos2)
        throw BitcoinExchange::BadInputException();
    yyyy = date.substr(0, pos1);
    mm = date.substr(pos1 + 1, pos2 - pos1 - 1);
    dd = date.substr(pos2 + 1);
    return (std::stoul(yyyy) << 16) | (std::stoul(mm)   << 8)  | (std::stoul(dd));
}

/**
 * @brief serialize_date - convert date to string format.
 * @param [in] val date.
 * @return string yyyy+mm+dd.
*/
std::string BitcoinExchange::serialize_date(unsigned long val)
{
    unsigned long year  = (val >> 16);
    unsigned long month = (val >> 8) & 0xFF;
    unsigned long day   = val & 0xFF;

    std::string yyyy = std::to_string(year);
    std::string mm   = std::to_string(month);
    std::string dd   = std::to_string(day);

    if (dd.length() < 2) dd = "0" + dd;
    if (mm.length() < 2) mm = "0" + mm;
    while (yyyy.length() < 4) yyyy = "0" + yyyy;

    return yyyy + "-" + mm + "-" + dd;
}

/**
 * @brief deserialize_value - convert date from string to double format.
 * @param [in] value string btc value.
 * @return date.
 * @throw BadInputException.
*/
double   BitcoinExchange::deserialize_value(const std::string& value)
{
    double fval;

    if (!is_valid_value(value))
        throw BitcoinExchange::BadInputException();
    fval = std::stod(value);
    if (std::isnan(fval) || std::isinf(fval))
        throw BitcoinExchange::BadInputException();
    return (fval);
}

/**
 * @brief serialize_value - convert value to string format.
 * @param [in] dval btc value.
 * @return string value with precision of 2 .
*/
std::string BitcoinExchange::serialize_value(double dval)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << dval;
    return oss.str();
}


/**
 * @brief is_valid_value - validate value.
 * @param [in] value string btc value.
 * @return true or false.
*/
bool BitcoinExchange::is_valid_value(const std::string& sval)
{

    if (sval.empty())
        return false;
    size_t i = 0;
    bool dot = false;
    size_t digits = 0;
    if (i < sval.size() && (sval[i] == '+' || sval[i] == '-'))
        i++;
    for (; i < sval.size(); ++i)
    {
        if (std::isdigit(sval[i]))
            digits++;
        else if (sval[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }
    return digits > 0;
}

/**
 * @brief is_valid_date - validate date.
 * @param [in] s string format {yyyy-mm-dd}.
 * @return true or false.
*/
bool BitcoinExchange::is_valid_date(const std::string& s)
{
    if (s.size() != 10 || s[4] != '-' || s[7] != '-')
        return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(s[i]))
            return false;
    }
    int month = std::stoi(s.substr(5, 2));
    int day   = std::stoi(s.substr(8, 2));
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

/**
 * @brief trim - remove extra spaces from start and end of string.
 * @param [in] line string to remove space from.
 * @return string without spaces.
*/
std::string BitcoinExchange::trim(const std::string& line)
{
    const char* WhiteSpace = " \t\v\r\n";
    std::size_t start = line.find_first_not_of(WhiteSpace);
    if (start == std::string::npos)
        return "";
    std::size_t end = line.find_last_not_of(WhiteSpace);
    return line.substr(start, end - start + 1);
}


/**
 * @override
 * @brief what - get exception error message .
 * @return exception error message .
*/
const char *BitcoinExchange::FileException::what(void) const throw()
{
    return ("Couldn't open file => ");
}

/**
 * @override
 * @brief what - get exception error message .
 * @return exception error message .
*/
const char *BitcoinExchange::NegativeNumberException::what(void) const throw()
{
    return ("Not a positive number.");
}

/**
 * @override
 * @brief what - get exception error message .
 * @return exception error message .
*/
const char *BitcoinExchange::TooLargeNumberException::what(void) const throw()
{
    return ("too large a number.");
}

/**
 * @override
 * @brief what - get exception error message .
 * @return exception error message .
*/
const char *BitcoinExchange::BadInputException::what(void) const throw()
{
    return ("Bad input => ");
}

/**
 * @override
 * @brief what - get exception error message .
 * @return exception error message .
*/
const char *BitcoinExchange::EmptyDatabaseException::what(void) const throw()
{
    return ("Empty database.");
}


/**
 * @override
 * @brief what - get exception error message .
 * @return exception error message .
*/
const char *BitcoinExchange::BadHeaderException::what(void) const throw()
{
    return ("Bad Header => ");
}

