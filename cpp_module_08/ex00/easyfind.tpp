#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include <algorithm>



/**
 * @brief easyfind - template function that find the first occurrence of target in the container . 
 * @param [in] ref reference to container,
 * @param [in] target item you want to search for .
 * @return reference to item you search for .
 * 
 * @throw std::runtime_error when target is not within the conatiner . 
*/
template <typename Tp>
typename Tp::value_type& easyfind(Tp &ref, int target)
{
    typename Tp::iterator ptr = std::find(ref.begin(), ref.end(), target);
    if (ptr != ref.end())
        return (*ptr);
    throw std::runtime_error("Could not find target in container .");
}

/**
 * @brief easyfind - template function that find the first occurrence of target in the container . 
 * @param [in] ref reference to const container,
 * @param [in] target item you want to search for .
 * @return const reference to item you search for .
 * 
 * @throw std::runtime_error when target is not within the conatiner . 
*/
template <typename Tp>
const typename Tp::value_type& easyfind(const Tp &ref, int target)
{
    typename Tp::const_iterator ptr = std::find(ref.begin(), ref.end(), target);
    if (ptr != ref.end())
        return (*ptr);
    throw std::runtime_error("Could not find target in container .");
}

#endif // EASYFIND_TPP

