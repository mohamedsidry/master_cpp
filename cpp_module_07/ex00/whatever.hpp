#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/**
 * @brief swap - swaps value in the two params .
 * @param [in, out] fst first param .
 * @param [in, out] snd second param .
*/
template<typename T>
void swap(T &fst, T &snd)
{
    T tmp;
    tmp = fst;
    fst = snd;
    snd = tmp;
}


/**
 * @brief min - find the min value of the two given params .
 * @param [in, out] fst first param .
 * @param [in, out] snd second param .
*/
template <typename T>
T min(T fst, T snd)
{
    if (fst < snd)
        return fst;
    else
        return snd;
}


/**
 * @brief max - find the max value of the two given params .
 * @param [in, out] fst first param .
 * @param [in, out] snd second param .
*/
template <typename T>
T max(T fst, T snd)
{
    if (fst > snd)
        return fst;
    else
        return snd;
}

#endif // WHATEVER_HPP


