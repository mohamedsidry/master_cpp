#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}


PmergeMe::PmergeMe(char *argv[])
{
    for (int i = 0; argv[i] != NULL; i++)
    {
        std::string tmp(argv[i]);
        if (!(PmergeMe::isValidInt(tmp)))
            throw PmergeMe::InputException();
        elements.push_back(std::atoi(argv[i]));
    }
}



PmergeMe::PmergeMe(const PmergeMe& copy):
elements(copy.elements)
{}



PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
        this->elements = other.elements;
    return (*this);
}


PmergeMe::~PmergeMe(){}



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

const char *PmergeMe::InputException::what() const throw()
{
    return ("Invalid input: all given numbers should be positive and under INT_MAX");
}

PmergeMe::InputException::~InputException()throw(){}


double PmergeMe::timediff_us( const struct timespec& start, const struct timespec& end) const
{
    double seconds = end.tv_sec - start.tv_sec;
    double nanoseconds = end.tv_nsec - start.tv_nsec;
    return seconds * 1000000.0 + nanoseconds / 1000.0;
}

void PmergeMe::compareVectorAndList(void) const
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
    
    std::cout << std::endl << "****************************************************" << std::endl;
    if (is_sorted<v_int>(v_ele))
        std::cout << "VECTOR : " << "Ok" << std::endl;
    else
        std::cout << "VECTOR : " << "KO" << std::endl;
    // std::cout << "VECTOR : " << "[";
    // for (std::vector<int>::iterator it = v_ele.begin(); it != v_ele.end(); it++)
    //     std::cout << *it << ", ";
    // std::cout << "]" << std::endl;
    std::cout << "VECTOR TIME TOOK  : " << std::fixed << std::setprecision(5) << timediff_us(v_stime, v_etime) << " us" << std::endl;
    std::cout << "VECTOR COMPS TOOK : " << v_compare_count << std::endl;

    std::cout << std::endl << "****************************************************" << std::endl;

    if (is_sorted<l_int>(l_ele))
        std::cout << "List : " << "Ok" << std::endl;
    else
        std::cout << "List : " << "KO" << std::endl;

    // std::cout << "LIST  : " << "[";
    // for (std::list<int>::iterator it = l_ele.begin(); it != l_ele.end(); it++)
    //     std::cout << *it << ", ";
    // std::cout << "]" << std::endl;
    std::cout << "LIST TIME TOOK  : " << std::fixed << std::setprecision(5) << timediff_us(l_stime, l_etime) << " us" << std::endl;
    std::cout << "LIST COMPS TOOK : " << l_compare_count << std::endl;

}








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


std::list<bool>::iterator PmergeMe::elementByIndex(std::list<bool>& items, size_t idx) const
{
    size_t i = 0;

    for (std::list<bool>::iterator it = items.begin(); it != items.end(); it++, i++)
        if (i == idx)
            return (it);
    return (items.end());
}

std::list<int>::iterator PmergeMe::elementByIndex(std::list<int>& items, size_t idx) const
{
    size_t i = 0;

    for (std::list<int>::iterator it = items.begin(); it != items.end(); it++, i++)
        if (i == idx)
            return (it);
    return (items.end());
}
std::list<std::pair<int, int> >::iterator PmergeMe::elementByIndex(std::list<std::pair<int, int> >& pairs, size_t idx) const
{
    size_t i = 0;

    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++, i++)
        if (i == idx)
            return (it);
    return (pairs.end());
}





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
