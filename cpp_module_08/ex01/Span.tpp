#ifndef SPAN_TPP
# define SPAN_TPP

#include "Span.hpp"


template <typename Tp>
Span<Tp>::Span()
:container_(), size_(0), offset_(0)
{
}


template <typename Tp>
Span<Tp>::Span(unsigned int N)
:container_(N), size_(N), offset_(0)
{

}


template <typename Tp>
Span<Tp>::Span(const Span& other)
:container_(other.size_), size_(other.size_), offset_(other.offset_)
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





#endif // SPAN_TPP

