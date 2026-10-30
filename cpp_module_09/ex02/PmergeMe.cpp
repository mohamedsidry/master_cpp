#include "PmergeMe.hpp"


/**
 * @brief PmergeMe default constructor .
*/

PmergeMe::PmergeMe(){}


/**
 * @brief PmergeMe param constructor .
 * @param [in] program argv list.
 * @param [in] program argc.
 */
PmergeMe::PmergeMe(char *argv[], int size)
{
    for (int i = 1; i < size; i++)
    {
        std::string tmp(argv[i]);
        if (!(PmergeMe::isValidInt(tmp)))
            throw PmergeMe::InputException();
        elements.push_back(std::atoi(argv[i]));
    }
    if (elements.size() == 0)
        throw PmergeMe::EmptyException();
}


/**
 * @brief PmergeMe copy constructor .
 * @param [in] program argv list.
 * @param [in] program argc.
 */

PmergeMe::PmergeMe(const PmergeMe& copy):
elements(copy.elements)
{}



/**
 * @brief PmergeMe copy assignment operator .
 * @param [in] program argv list.
 * @param [in] program argc.
 */
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
        this->elements = other.elements;
    return (*this);
}


/**
 * @brief PmergeMe default destructor .
*/
PmergeMe::~PmergeMe(){}


/**
 * @brief isValidInt check if valid int .
 * @param [in] string number to check.
 * @return true if number is positive and within INT_MAX range.
*/
bool PmergeMe::isValidInt(std::string& str)
{
    unsigned long current = 0;
    unsigned long max = INT_MAX;
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        if(!isdigit(*it))
            return (false);
        current = current * 10 - 48 + (*it);
        if (current > max)
            return (false);
    }
    return (true);
}


/**
 * @brief what get the error message for invalid inputs .
 * @return error message.
*/
const char *PmergeMe::InputException::what() const throw()
{
    return ("Invalid input: all given numbers should be positive and under INT_MAX");
}

/**
 * @brief InputException default destructor .
*/
PmergeMe::InputException::~InputException()throw(){}

/**
 * @brief what get the error message for empty inputs .
 * @return error message.
*/
const char *PmergeMe::EmptyException::what() const throw()
{
    return ("Nothing to sort .");
}

/**
 * @brief EmptyException default destructor .
*/
PmergeMe::EmptyException::~EmptyException()throw(){}


/**
 * @brief  timediff_us callculate time different in mecroseconds .
 * @param [in] start time.
 * @param [in] end time.
 * @return time between start and end in mecroseconds.
*/
double PmergeMe::timediff_us( const struct timespec& start, const struct timespec& end) const
{
    double seconds = end.tv_sec - start.tv_sec;
    double nanoseconds = end.tv_nsec - start.tv_nsec;
    return seconds * 1000000.0 + nanoseconds / 1000.0;
}



/**
 * @brief  banchMarkVectorListDetailed compaire time taken to sort list and vector using ford-johnson with detailed info .
*/
void PmergeMe::banchMarkVectorListDetailed(void) const
{

    std::string RED, GREEN, YELLOW, BLUE, PURPLE, RESET;

    RED = "\033[1;31m";
    GREEN = "\033[1;32m";
    YELLOW = "\033[1;33m";
    BLUE = "\033[1;34m";
    PURPLE = "\033[1;35m";
    RESET = "\033[0m";
    
    int v_compare_count = 0;
    struct timespec v_stime, v_itime, v_etime;
    
    int l_compare_count = 0;
    struct timespec l_stime, l_itime , l_etime;
    
    clock_gettime(CLOCK_MONOTONIC, &v_stime);
    v_int v_ele = serialize<v_int>();
    clock_gettime(CLOCK_MONOTONIC, &v_itime);
    ford_johnson_vector(v_ele, v_compare_count);
    clock_gettime(CLOCK_MONOTONIC, &v_etime);
    
    
    clock_gettime(CLOCK_MONOTONIC, &l_stime);
    l_int l_ele = serialize<l_int>();
    clock_gettime(CLOCK_MONOTONIC, &l_itime);
    ford_johnson_list(l_ele, l_compare_count);
    clock_gettime(CLOCK_MONOTONIC, &l_etime);
    

    std::cout << GREEN << std::endl;
    std::cout << "************************************************************************************************************" << std::endl;
    std::cout << "****************************************** ford johnson banchmark ******************************************" << std::endl;
    std::cout << "************************************************************************************************************" << std::endl;
    std::cout << "* UNSORTED ELEMENTS : " << RED;
    for (size_t i = 0; i < elements.size(); i++)
        std::cout << elements[i] << (((i + 1) < elements.size())  ? ", " : "");
    std::cout << GREEN << std::endl;
    std::cout << "* SORTED ELEMENTS VECTOR : " << PURPLE;
    for (size_t i = 0; i < v_ele.size(); i++)
        std::cout << v_ele[i] << (((i + 1) < v_ele.size())  ? ", " : "");
    std::cout << GREEN << std::endl;
    std::cout << "* SORTED ELEMENTS LIST   : " << YELLOW;
    for (size_t i = 0; i < v_ele.size(); i++)
        std::cout << *elementByIndex(l_ele, i) << (((i + 1) < v_ele.size())  ? ", " : "");
    std::cout << GREEN << std::endl;
    std::cout << "* CONTAINER SIZE : "  << BLUE << elements.size()  << GREEN << std::endl;
    std::cout << "* BOTH LIST AND VECTOR ARE SORTED : " << (is_sorted<std::list<int> >(l_ele) && is_sorted<std::vector<int> >(v_ele)  ? "TRUE" : "FALSE") << std::endl;
    std::cout << "* TIME TOOK TO INIT WITH VECTOR : " << BLUE << std::fixed << std::setprecision(5) << timediff_us(v_stime, v_itime) << " μs" << GREEN << std::endl;
    std::cout << "* TIME TOOK TO SORT WITH VECTOR : " << PURPLE << std::fixed << std::setprecision(5) << timediff_us(v_stime, v_etime) << " μs" << GREEN << std::endl;
    std::cout << "* COMPARISONS TOOK TO SORT WITH VECTOR  : " << BLUE << v_compare_count << GREEN << std::endl;
    std::cout << "* TIME TOOK TO INIT WITH LIST   : " << BLUE << std::fixed << std::setprecision(5) << timediff_us(l_stime, l_itime) << " μs" << GREEN << std::endl;
    std::cout << "* TIME TOOK TO SORT WITH LIST   : " << YELLOW << std::fixed << std::setprecision(5) << timediff_us(l_stime, l_etime) << " μs" << GREEN << std::endl;
    std::cout << "* COMPARISONS TOOK TO SORT WITH LIST    : " << BLUE << l_compare_count  << GREEN << std::endl;
    std::cout << "* TIME DIFF BETWEEN LIST AND VECTOR : " << RED << std::fixed << std::setprecision(5) << (timediff_us(l_stime, l_etime)  > timediff_us(v_stime, v_etime) ?  timediff_us(l_stime, l_etime)  - timediff_us(v_stime, v_etime) : timediff_us(v_stime, v_etime)  - timediff_us(l_stime, l_etime)) << " μs" << GREEN << std::endl;
    std::cout << "* TOTAL TIME DIFF PERCENTAGE  : " << RED << "-" << (timediff_us(l_stime, l_etime)  > timediff_us(v_stime, v_etime) ? ((timediff_us(l_stime, l_etime)  - timediff_us(v_stime, v_etime)) * 100 / timediff_us(l_stime, l_etime)) : ((timediff_us(v_stime, v_etime)  - timediff_us(l_stime, l_etime)) * 100 / timediff_us(v_stime, v_etime)) ) << " %" << GREEN << std::endl;
    std::cout << "* WHICH ONE BETTER : " << RED << (timediff_us(l_stime, l_etime)  > timediff_us(v_stime, v_etime) ? "{VECTOR}" : "{LIST}") << GREEN << std::endl;
    std::cout << "************************************************************************************************************" << std::endl;
    std::cout << RESET << std::endl;

}


/**
 * @brief  banchMarkVectorListDetailed compaire time taken to sort list and vector using ford-johnson .
*/
void PmergeMe::banchMarkVectorList(void) const
{
    v_int v_ele = serialize<v_int>();
    l_int l_ele = serialize<l_int>();
    
    int v_compare_count = 0;
    struct timespec v_stime, v_etime;
    
    int l_compare_count = 0;
    struct timespec l_stime, l_etime;
    
    clock_gettime(CLOCK_MONOTONIC, &v_stime);
    ford_johnson_vector(v_ele, v_compare_count);
    clock_gettime(CLOCK_MONOTONIC, &v_etime);
    
    
    clock_gettime(CLOCK_MONOTONIC, &l_stime);
    ford_johnson_list(l_ele, l_compare_count);
    clock_gettime(CLOCK_MONOTONIC, &l_etime);

    std::cout << "Before:";
    for (size_t i = 0; i < elements.size(); i++)
        std::cout << " " << elements[i];
    std::cout << std::endl;
    std::cout << "After:";
    for (size_t i = 0; i < v_ele.size(); i++)
        std::cout << " " << v_ele[i];
    std::cout << std::endl;
    std::cout << "Time to process a range of " << v_ele.size() << " elements with std::vector<int> : " << std::fixed << std::setprecision(5) << timediff_us(v_stime, v_etime) << " μs" << std::endl;
    std::cout << "Time to process a range of " << l_ele.size() << " elements with std::list<int> : " << std::fixed << std::setprecision(5) << timediff_us(l_stime, l_etime) << " μs" << std::endl;

}







/**
 * @brief  ford_johnson_vector sort vector with ford-johnson algorithm  .
 * @param [in] items vector of numbers.
 * @param [in, out] count counter for number of comparisons  .
*/
void PmergeMe::ford_johnson_vector(std::vector<int>& items, int& count) const
{
    if (items.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 1; i < items.size(); i+=2)
        pairs.push_back(sorted_pair(items[i], items[i - 1], count));
    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].first);

    ford_johnson_vector(larger, count);
    std::vector<std::pair<int, int> > ordered;
    std::vector<bool> used(pairs.size(), false);
    for (size_t i = 0; i < larger.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].first == larger[i])
            {
                used[j] = true;
                ordered.push_back(pairs[j]);
                break;
            }
        }
    }
    pairs = ordered;
    std::vector<int> chain;
    chain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        chain.push_back(pairs[i].first);
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);
    bool hasStraggler = items.size() % 2;
    if (hasStraggler)
        pend.push_back(items[items.size() - 1]);

    std::vector<size_t> order = insertion_order(pend.size());
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t j = order[k], end;
        if (j <= pairs.size())
            end = std::find(chain.begin(), chain.end(), pairs[j - 1].first) - chain.begin();
        else
            end = chain.size();
        binary_insert_vector(chain, end, pend[j - 1], count);
    }
    items = chain;
}



/**
 * @brief  ford_johnson_list sort vector with ford-johnson algorithm  .
 * @param [in] items list of numbers.
 * @param [in, out] count counter for number of comparisons  .
*/
void PmergeMe::ford_johnson_list(std::list<int>& items, int& count) const
{
    if (items.size() <= 1)
        return;

    std::list<std::pair<int, int> > pairs;
    std::list<int> larger;

    for (size_t i = 1; i < items.size(); i+=2)
        pairs.push_back(sorted_pair(*elementByIndex(items, i), *elementByIndex(items, i - 1), count));

    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        larger.push_back(it->first);

    ford_johnson_list(larger, count);
    std::list<std::pair<int, int> > ordered;
    std::list<bool> used(pairs.size(), false);

    for (std::list<int>::iterator it = larger.begin(); it != larger.end(); it++)
    {
        size_t idx = 0;
        for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); pit++)
        {
            std::list<bool>::iterator curr = elementByIndex(used, idx++);
            if (!*(curr) && pit->first == *it)
            {
                *curr = true;
                ordered.push_back(*pit);
                break;
            }
        }
    }
    pairs = ordered;
    std::list<int> chain, pend;
    chain.push_back(pairs.front().second);
    for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); pit++)
    {
        chain.push_back(pit->first);
        pend.push_back(pit->second);
    }
    bool hasStraggler = items.size() % 2;
    if (hasStraggler)
        pend.push_back(*elementByIndex(items, items.size() - 1));

    std::vector<size_t> order = insertion_order(pend.size());
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t j = order[k], end;

        if (j <= pairs.size())
            end = list_range(chain, std::find(chain.begin(), chain.end(), elementByIndex(pairs, j - 1)->first));
        else
            end = chain.size();
        binary_insert_list(chain, end, *elementByIndex(pend, j - 1), count);
    }
    items = chain;
}


/**
 * @brief  list_range calculate the range from start to target element.
 * @param [in] chain list of numbers.
 * @param [in] target element.
 * @return range from start to target
*/
size_t PmergeMe::list_range(std::list<int>& chain, std::list<int>::iterator end) const
{
    size_t i = 0;

    for (std::list<int>::iterator it = chain.begin(); it != chain.end(); ++it, ++i)
    {
        if (it == end)
            return i;
    }
    return i;
}



/**
 * @overload 
 * @brief  elementByIndex get item in index.
 * @param [in] itmes list of items.
 * @param [in] idx element position.
 * @return item in that index .
*/
std::list<bool>::iterator PmergeMe::elementByIndex(std::list<bool>& items, size_t idx) const
{
    size_t i = 0;

    for (std::list<bool>::iterator it = items.begin(); it != items.end(); it++, i++)
        if (i == idx)
            return (it);
    return (items.end());
}

/**
 * @overload 
 * @brief  elementByIndex get item in index.
 * @param [in] itmes list of itmes.
 * @param [in] idx element position.
 * @return item in that index .

*/
std::list<int>::iterator PmergeMe::elementByIndex(std::list<int>& items, size_t idx) const
{
    size_t i = 0;

    for (std::list<int>::iterator it = items.begin(); it != items.end(); it++, i++)
        if (i == idx)
            return (it);
    return (items.end());
}

/**
 * @overload 
 * @brief  elementByIndex get item in index.
 * @param [in] pairs list of items.
 * @param [in] idx element position.
 * @return item in that index .
*/
std::list<std::pair<int, int> >::iterator PmergeMe::elementByIndex(std::list<std::pair<int, int> >& pairs, size_t idx) const
{
    size_t i = 0;

    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++, i++)
        if (i == idx)
            return (it);
    return (pairs.end());
}




/**
 * @overload 
 * @brief  binary_insert_vector insert number to vector with binary insertion algorithm .
 * @param [in, out] chain vector of numbers.
 * @param [in] end range of insertion.
 * @param [in] value number to insert position.
 * @param [in, out] count counter for number of comparisons  .
*/
void PmergeMe::binary_insert_vector(std::vector<int>& chain, size_t end, int value, int& count) const
{
    size_t lo = 0, hi = end;
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        ++count;
        if (chain[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, value);
}


/**
 * @overload 
 * @brief  binary_insert_list insert number to list with binary insertion algorithm .
 * @param [in, out] chain list of numbers.
 * @param [in] end range of insertion.
 * @param [in] value number to insert position.
 * @param [in, out] count counter for number of comparisons  .
*/
void PmergeMe::binary_insert_list(std::list<int>& chain, size_t end, int value, int& count) const
{
    size_t lo = 0, hi = end;
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        ++count;
        if (*elementByIndex(chain, mid) < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(elementByIndex(chain, lo), value);
}


/**
 * @overload 
 * @brief  insertion_order generate a vector of indexes in which the pend elements should be pushed to cost less comparisons using jackobsthal algorithm .
 * @param [in] size of conatiner .
 * @return jackobsthal sequances in vector .
 */
std::vector<size_t> PmergeMe::insertion_order(size_t m) const
{
    std::vector<size_t> order;
    size_t prev = 1;
    size_t cur = 3;
    while (prev < m)
    {
        size_t top = (cur < m) ? cur : m;
        for (size_t j = top; j > prev; j--)
            order.push_back(j);
        size_t next = cur + 2 * prev;
        prev = cur;
        cur = next;
    }
    return order;
}


/**
 * @overload 
 * @brief  sorted_pair takes to numbers compaire and form a pair where the bigger in 1st place and small in 2nd place .
 * @param [in] a number .
 * @param [in] b number .
 * @param [in] counter number .
 * @return  paire where a is in 1st palce and b in 2nd place .
 */
std::pair<int, int> PmergeMe::sorted_pair(int a, int b, int &counter) const
{
    std::pair<int, int> p(a, b);
    counter++;
    if (a <  b)
        p = std::make_pair(b, a);
    return (p);
}



/**
// NOTE: Basic merge sort used for comparing time and operation count .

void PmergeMe::merge(std::vector<int>& arr, int start, int mid, int end, int &count) const
{
    int n1, n2;
    
    n1 = mid - start + 1;
    n2 = end - mid;
    std::vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[start + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = arr[mid + i + 1];
    

    int k, i = 0, j = 0;
    for (k = start; i < n1 && j < n2; k++)
    {
        count++;
        if (arr1[i] <= arr2[j])
            arr[k] = arr1[i++];
        else
            arr[k] = arr2[j++];
    }

    while (i < n1)
        arr[k++] = arr1[i++];

    while (j < n2)
        arr[k++] = arr2[j++];
}

void PmergeMe::merge_sort(std::vector<int>& arr, int start, int end, int& count) const
{
    if (start == end)
        return ;
    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid, count);
    merge_sort(arr, mid + 1, end, count);
    merge(arr, start, mid, end, count);
}
*/
