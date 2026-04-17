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
:container_(other.size_), size_(other.size_), capacity_(other.offset_)
{

}


template <typename Tp>
Span<Tp>& Span<Tp>::operator=(const Span& other)
{
    if (this != &other)
    {
        Tp::operator=(other.container_);
        this->size_ = other.size_;
        this->offset_ = other.offset_;
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
const char * Span<Tp>::ExceptionFullContainer::what() const throw()
{
    return ("no space for the new added item .");
}

#endif // SPAN_TPP

