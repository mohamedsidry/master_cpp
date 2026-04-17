#ifndef SPAN_TPP
# define SPAN_TPP

#include "Span.hpp"


template <typename Tp>
Span<Tp>::Span()
:container_(), size_(0), capacity_(0)
{
}


template <typename Tp>
Span<Tp>::Span(unsigned int N)
:container_(N), size_(N), capacity_(0)
{

}


template <typename Tp>
Span<Tp>::Span(const Span& other)
:container_(other.size_), size_(other.size_), capacity_(other.capacity_)
{

}


template <typename Tp>
Span<Tp>& Span<Tp>::operator=(const Span& other)
{
    if (this != &other)
    {
        Tp::operator=(other.container_);
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;
    }
    return (this);
}



template <typename Tp>
void Span<Tp>::addNumber(int number)
{
    if (capacity_ < size_)
    {
        container_[capacity_] = number;
        ++capacity_;
        return ;
    }
    throw Span::ExceptionFullContainer();
}


template <typename Tp>
unsigned int Span<Tp>::longestSpan(void) const
{
    if (capacity_ == 0)
        throw Span::ExceptionEmptyContainer();
    else if (capacity_ == 1)
        throw Span::ExceptionNotEnoughNumbers();
    return ABS(max() - min());
}


template <typename Tp>
int Span<Tp>::min(void) const
{
    int _min = INT_MAX ;
    for (typename Tp::const_iterator it = container_.begin(); it != container_.end(); it++)
    {
        if (_min > *it)
            _min = *it;
    }
    return _min;
}

template <typename Tp>
int Span<Tp>::max(void) const
{
    int _max = INT_MIN;
    for (typename Tp::const_iterator it = container_.begin(); it != container_.end(); it++)
    {
        if (_max < *it)
            _max = *it;
    }
    return _max;
}


template <typename Tp>
const char * Span<Tp>::ExceptionFullContainer::what() const throw()
{
    return ("no space left for adding a number .");
}

template <typename Tp>
const char * Span<Tp>::ExceptionEmptyContainer::what() const throw()
{
    return ("operation on empty container .");
}

template <typename Tp>
const char * Span<Tp>::ExceptionNotEnoughNumbers::what() const throw()
{
    return ("container does not contain enough numbers to preform this operation .");
}

#endif // SPAN_TPP

