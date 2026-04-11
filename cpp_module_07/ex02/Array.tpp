#ifndef ARRAY_TPP
 #define ARRAY_TPP
 #include "Array.hpp"




template <typename T>
Array<T>::Array():
arr_(nullptr),
size_(0)
{
}


template <typename T>
Array<T>::Array(unsigned int n):
size_(n)
{
    if (size_ > 0)
        arr_ = new T[size_]();
    else
        arr_ = nullptr;
}

template <typename T>
Array<T>::Array(const Array<T>& other):
size_(other.size_)
{
    if (other.arr_)
    {
        this->arr_ = new T[size_]();
        for (unsigned int i = 0; i < size_; i++)
            this->arr_[i] = other.arr_[i];
    }
    else
        this->arr_ = nullptr;
}


template <typename T>
Array<T>::~Array()
{
    delete [] arr_;
}



template <typename T>
unsigned int Array<T>::size(void) const
{
    return (this->size_);
}




template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete [] arr_;
        arr_ = nullptr;
        size_ = other.size_;
        if (size_ > 0)
        {
            this->arr_ = new T[size_]();
            for (unsigned int i = 0; i < size_; i++)
                this->arr_[i] = other.arr_[i];
        }
    }
    return (*this);
}



template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx >= this->size_)
        throw std::exception();
    return this->arr_[idx];
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx >= this->size_)
        throw Array<T>::ExceptionOutOfBounds();
    return this->arr_[idx];
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& obj)
{
    os << "[";
    for (unsigned int i = 0 ; i < obj.size(); i++)
    {
        os << obj[i];
        if (i < obj.size() - 1)
            os << ", ";
    }
    os << "]";
    if (obj.size() == 0)
        os << ": (Empty) .";
    else
        os << ": ( " << obj.size() << " items ) .";
    return os;
}



template <typename T>
const char *Array<T>::ExceptionOutOfBounds::what(void) const throw()
{
    return "index out of bounds .";
}

#endif // ARRAY_TPP
