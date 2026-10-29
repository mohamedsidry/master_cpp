#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <list>
#include <utility>
#include <climits>
#include <ctime>
#include <iomanip>


class PmergeMe
{
    private:
        std::vector<int> elements;
        bool isValidInt(std::string& str);
        double timediff_us( const struct timespec& start, const struct timespec& end) const;
        std::pair<int, int> sorted_pair(int a, int b, int &counter) const;
        std::vector<size_t> insertion_order(size_t m) const;

        void binary_insert_vector(std::vector<int>& chain, size_t end, int value, int& count) const;
        void ford_johnson_vector(std::vector<int>& items, int& count) const;

        void binary_insert_list(std::list<int>& chain, size_t end, int value, int& count) const;
        void ford_johnson_list(std::list<int>& items, int& count) const;

        std::list<int>::iterator elementByIndex(std::list<int>& items, size_t idx) const;
        std::list<std::pair<int, int> >::iterator elementByIndex(std::list<std::pair<int, int> >& pairs, size_t idx) const;
        std::list<bool>::iterator elementByIndex(std::list<bool>& items, size_t idx) const;
        size_t list_range(std::list<int> & chain, std::list<int>::iterator end) const;

    public:
    
        typedef std::vector<int>    v_int;
        typedef std::list<int>      l_int;
        typedef std::vector<std::pair <int, int> >   v_pair;
        typedef std::list<std::pair <int, int> >     l_pair;
        PmergeMe();
        PmergeMe(char *input[]);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
        template <typename T>
        bool is_sorted(T& elements) const
        {
            typename T::iterator prev = elements.begin();

            if (prev == elements.end())
                return true;
            typename T::iterator it = prev;
            ++it;
            for (; it != elements.end(); ++it, ++prev)
            {
                if (*it < *prev)
                    return false;
            }
            return true;
        }

        template <typename T>
        T serialize(void) const
        {
            T items;
            for (size_t i = 0; i < elements.size(); i++)
                items.push_back(elements[i]);
            return items;
        }

        class InputException: public std::exception
        {
            public:
                const char *what(void) const throw();
                virtual ~InputException() throw();
        };
        void compareVectorAndList(void) const;

        /**
            NOTE: Basic merge sort used for comparing time and operation count .
            void merge(std::vector<int>& arr, int start, int mid, int end, int &count) const;
            void merge_sort(std::vector<int>& arr, int start, int end, int& ) const;        
        */
};

#endif /* PMERGEME_HPP */
