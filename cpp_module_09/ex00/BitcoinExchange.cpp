#include "BitcoinExchange.hpp"

std::string BitcoinExchange::DEFAULT_DB = "data.csv";


BitcoinExchange::BitcoinExchange()
:database_src_(BitcoinExchange::DEFAULT_DB)
{
    init();
}

BitcoinExchange::BitcoinExchange(const char *path)
:database_src_(path)
{
    init();
}


BitcoinExchange::BitcoinExchange(const std::string& path)
:database_src_(path)
{
    init();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
:database_src_(other.database_src_), database_(other.database_)
{}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        database_src_ = other.database_src_;
        database_ = other.database_;
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange()
{}




void BitcoinExchange::init(void)
{
    std::ifstream ifs;
    try
    {
        ifs.open(database_src_, std::ifstream::in);
        if (ifs.fail())
            throw BitcoinExchange::FileException();
        load_database(ifs);
        ifs.close();
    }catch (const std::exception& e)
    {
        std::cerr << "\033[1;31mError : \033[0m" << e.what() << database_src_ << std::endl;
    }
}

void BitcoinExchange::load_database(std::ifstream& ifs)
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
                std::cerr << "\033[1;31mError : \033[0m" << "bad header => " << buffer << std::endl;
                return;
            }
            ++idx;
            continue;
        }
        try
        {
            ele = BitcoinExchange::deserialize(buffer, ",");
            database_.insert(ele);
        } catch (const std::exception& e)
        {
            std::cerr << "\033[1;31mError : " << "\033[0m" << e.what() << buffer << std::endl;
        }
    } 
}

void BitcoinExchange::data_processing(std::ifstream& ifs) const 
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
                std::cerr << "\033[1;31mError : \033[0m" << "bad header => " << buffer << std::endl;
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
            std::cout << "\033[1;31mError : \033[0m" << e.what() << "=> " << buffer << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[1;31mError : \033[0m" << e.what() << std::endl;
        }
    };
}


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
        data_processing(ifs);
        ifs.close();
    } catch(const BitcoinExchange::FileException& e)
    {
        std::cout << "\033[1;31mError : \033[0m" << e.what() << file << std::endl;
    }
     catch(const BitcoinExchange::EmptyDatabaseException& e)
    {
        std::cout << "\033[1;31mError : \033[0m" << e.what()<< std::endl;
    }
}

void BitcoinExchange::evaluate(const std::string& file) const
{
    evaluate(file.c_str());
}



// Static methods

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

std::string BitcoinExchange::serialize(const std::pair<unsigned long, double>& pval, const std::string& sep)
{
    return BitcoinExchange::serialize_date(pval.first) + sep + BitcoinExchange::serialize_value(pval.second);
}

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

std::string BitcoinExchange::serialize_value(double fval)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << fval;
    return oss.str();
}

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

bool BitcoinExchange::is_valid_date(const std::string& s)
{
    if (s.size() != 10 || s[4] != '-' || s[7] != '-')
        return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(s[i]))
            return false;
    }
    int year  = std::stoi(s.substr(0, 4));
    int month = std::stoi(s.substr(5, 2));
    int day   = std::stoi(s.substr(8, 2));
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeap(year))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

bool BitcoinExchange::isLeap(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

std::string BitcoinExchange::trim(const std::string& line)
{
    const char* WhiteSpace = " \t\v\r\n";
    std::size_t start = line.find_first_not_of(WhiteSpace);
    if (start == std::string::npos)
        return "";
    std::size_t end = line.find_last_not_of(WhiteSpace);
    return line.substr(start, end - start + 1);
}


// Exceptions 
const char *BitcoinExchange::FileException::what(void) const throw()
{
    return ("Couldn't open file : ");
}

const char *BitcoinExchange::NegativeNumberException::what(void) const throw()
{
    return ("Not a positive number.");
}

const char *BitcoinExchange::TooLargeNumberException::what(void) const throw()
{
    return ("too large a number.");
}

const char *BitcoinExchange::BadInputException::what(void) const throw()
{
    return ("Bad input ");
}

const char *BitcoinExchange::EmptyDatabaseException::what(void) const throw()
{
    return ("Empty database.");
}
