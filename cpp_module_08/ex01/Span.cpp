#include "Span.hpp"


/**
 * @brief Span - default constructor .
 * note : container function reserve manage capacity not the size .
 */
Span::Span()
: maxSize_(0)
{
    data_.reserve(0);
}

/**
 * @brief Span - param constructor .
 * @param [in] N number of ints span can hold .
 */
Span::Span(unsigned int N)
: maxSize_(N)
{
    data_.reserve(N);
}

/**
 * @brief Span - param constructor .
 * @param [in] other  object to copy from .
 */
Span::Span(const Span& other)
:data_(other.data_), maxSize_(other.maxSize_)
{}

/**
 * @brief Span= - copy asign operator .
 * @param [in] other  object to copy from .
 * @return Span object .
 */
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->data_ = other.data_;
        this->maxSize_ = other.maxSize_;
    }
    return (*this);
}

/**
 * @brief Span -  destructor .
 */
Span::~Span()
{
}

/**
 * @brief addNumber - api to add a number to container .
 * @param [in] number value to add .
 * 
 * @throws Span::ExceptionFullContainer when no left space in container .
 */
void Span::addNumber(int number)
{
    if (data_.size() < maxSize_)
        data_.push_back(number);
    else
        throw Span::ExceptionFullContainer();
}

/**
 * @brief longestSpan - calc the longest distance .
 * @return longest distance .
 * 
 * @throws Span::ExceptionNotEnoughNumbers when the container is empty of has only one element .
 */
unsigned int Span::longestSpan(void) const
{
    if (data_.size() < 2)
        throw Span::ExceptionNotEnoughNumbers();
    int min = *std::min_element(data_.begin(), data_.end());
    int max = *std::max_element(data_.begin(), data_.end());
    return  abs(max - min);
}


/**
 * @brief longestSpan - calc the shortestSpan distance .
 * @return shortestSpan distance .
 * 
 * @throws Span::ExceptionNotEnoughNumbers when the container is empty of has only one element .
 */
unsigned int Span::shortestSpan(void) const
{
    if (data_.size() < 2)
        throw Span::ExceptionNotEnoughNumbers();
    std::vector<int> tmp = data_;
    std::sort(tmp.begin(), tmp.end());
    unsigned int minSpen = abs(tmp[1] - tmp[0]);
    for (size_t i = 1; i < data_.size() - 1; i++)
    {
        unsigned int span = abs(tmp[i + 1] - tmp[i]);
        if (span < minSpen)
            minSpen = span;
    }
    return minSpen;
}


/**
 * @brief Span::ExceptionFullContainer::what - (override) get the exception message .
 * @return message of exception .
 */
const char * Span::ExceptionFullContainer::what() const throw()
{
    return ("no space left for adding a number .");
}

/**
 * @brief Span::ExceptionNotEnoughNumbers::what - (override) get the exception message .
 * @return message of exception .
 */
const char * Span::ExceptionNotEnoughNumbers::what() const throw()
{
    return ("container does not contain enough numbers to perform this operation .");
}


