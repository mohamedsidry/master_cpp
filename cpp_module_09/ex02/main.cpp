#include "PmergeMe.hpp"




int main(int argc, char *argv[])
{
    (void)argc;
    try
    {
        PmergeMe pm(&argv[1]);
        pm.compareVectorAndList();
        
    } catch (const PmergeMe::InputException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

