#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/**
 * @brief iter - iterate over an array of elements apply function over each them .
 * @param [in] arr array of elements .
 * @param [in] length length of the array .
 * @param [in] func pointer to function that takes element reference .
*/
template <typename T>
void iter(T arr[], const size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; i++)
        func(arr[i]);
}

/**
 * @brief iter - (overload) iterate over an array of elements apply function over each of them .
 * @param [in] arr const array of elements .
 * @param [in] length length of the array .
 * @param [in] func pointer to function that takes const element reference .
*/
template <typename T>
void iter(const T arr[], const size_t length, void (*func)(const T&))
{
    for (size_t i = 0 ; i < length; i++)
        func(arr[i]);
}



#endif // ITER_HPP
