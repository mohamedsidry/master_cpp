#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

/**
 * @brief Array<T> - template class that holds an array of objects .
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
        void show_array(void) const;
        void set_seq(unsigned int);
        unsigned int size(void) const;
        class ExceptionOutOfBounds : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

template <typename T>
std::ostream& operator << (const std::ostream& os, const Array<T>& ref);

#include "Array.tpp"

#endif // ARRAY_HPP

