#ifndef ARRAY_TPP
 #define ARRAY_TPP
 #include "Array.hpp"



/**
 * @brief Array<T> default constructor .
 */
template <typename T>
Array<T>::Array():
arr_(NULL),
size_(0){}


/**
 * @brief Array<T> constructor with param .
 * @param [in] n size of array .
 */
template <typename T>
Array<T>::Array(unsigned int n):
size_(n)
{
    if (size_ > 0)
        arr_ = new T[size_]();
    else
        arr_ = NULL;
}


/**
 * @brief Array<T> copy constructor .
 * @param [in] other object to copy from .
 */
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
        this->arr_ = NULL;
}


/**
 * @brief Array<T> destructor .
 */
template <typename T>
Array<T>::~Array()
{
    delete [] arr_;
}


/**
 * @brief size get the length of the array .
 * @return number of item in the array .
 */
template <typename T>
unsigned int Array<T>::size(void) const
{
    return (this->size_);
}



/**
 * @brief Array<T>= copy asignment operator .
 * @param [in] other object to copy from .
 * @return new object with deep copy of other data . 
 */
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete [] arr_;
        arr_ = NULL;
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


/**
 * @brief operator[] get element by idex .
 * @param [in] idx index of element .
 * @return const element in index idx .
 * @throws Array<T>::ExceptionOutOfBounds if index out of range .
 * @note overload of operator[]
 */
template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx >= this->size_)
        throw std::exception();
    return this->arr_[idx];
}

/**
 * @brief operator[] get element by idex .
 * @param [in] idx index of element .
 * @return element in index idx .
 * @throws Array<T>::ExceptionOutOfBounds if index out of range .
 * @note overload of operator[]
 */
template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx >= this->size_)
        throw Array<T>::ExceptionOutOfBounds();
    return this->arr_[idx];
}

/**
 * @brief operator<< display object into standart output stream .
 * @param [in] os output stream .
 * @param [in] obj array<T> object reference .
 * @return output stream .
 * @note overload of operator<<
 */
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


/**
 * @brief Array<T>::ExceptionOutOfBounds::what overload exception message .
 * @return error message .
 * @note overload of std::exception::what .
 */
template <typename T>
const char *Array<T>::ExceptionOutOfBounds::what(void) const throw()
{
    return "index out of bounds .";
}

#endif // ARRAY_TPP
