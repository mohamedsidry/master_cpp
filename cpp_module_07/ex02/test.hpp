#ifndef TEST_HPP

#define TEST_HPP

#include "Array.hpp"

template <typename T>
void Array<T>::show_array(void) const
{
    std::for_each(arr_, arr_ + size_, [](int it){std::cout << "value is : " << it << std::endl;});
}

template <typename T>
void Array<T>::set_seq(unsigned int seq)
{
    for (unsigned int i = 0 ; i < size_; i++)
        arr_[i] = i * seq;
}


#endif //TEST_HPP


