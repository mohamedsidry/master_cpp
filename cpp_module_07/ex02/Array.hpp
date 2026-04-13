#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

/**
 * @brief Array<T> - template class that holds an array of any type of objects .
 * Detailed this class aimed to store an array of objects of any type, copy an array, retrieve an object by index .
*/
template <typename T>
class Array
{
    private:
        T* arr_;
        unsigned int size_;
    public:
        Array();
        Array(const Array&);
        Array& operator=(const Array&);
        ~Array();
        Array(unsigned int);
        const T& operator[](unsigned int idx) const;
        T& operator[](unsigned int idx);
        unsigned int size(void) const;
        class ExceptionOutOfBounds : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
        template <typename Func>
        void iter(Func func)
        {
            for (unsigned int i = 0; i < size_; i++)
            {
                func(arr_[i]);
            }
        }
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Array<T>& ref);

#include "Array.tpp"



#endif // ARRAY_HPP

