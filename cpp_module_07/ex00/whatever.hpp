#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &fst, T &snd)
{
    T tmp;
    tmp = fst;
    fst = snd;
    snd = tmp;
}



template <typename T>
T min(T fst, T snd)
{
    if (fst < snd)
        return fst;
    else
        return snd;
}



template <typename T>
T max(T fst, T snd)
{
    if (fst > snd)
        return fst;
    else
        return snd;
}

#endif // WHATEVER_HPP


