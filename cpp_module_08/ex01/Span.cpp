#include "Span.hpp"

Span::Span()
: maxSize_(0)
{
    data_.reserve(0);
}

Span::Span(unsigned int N)
: maxSize_(N)
{
    data_.reserve(N);
}

Span::Span(const Span& other)
:data_(other.data_), maxSize_(other.maxSize_)
{}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->data_ = other.data_;
        this->maxSize_ = other.maxSize_;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (data_.size() < maxSize_)
        data_.push_back(number);
    else
        throw Span::ExceptionFullContainer();
}



unsigned int Span::longestSpan(void) const
{
    if (data_.size() < 2)
        throw Span::ExceptionNotEnoughNumbers();
    int min = *std::min_element(data_.begin(), data_.end());
    int max = *std::max_element(data_.begin(), data_.end());
    return  abs(max - min);
}

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

const char * Span::ExceptionFullContainer::what() const throw()
{
    return ("no space left for adding a number .");
}

const char * Span::ExceptionNotEnoughNumbers::what() const throw()
{
    return ("container does not contain enough numbers to perform this operation .");
}


