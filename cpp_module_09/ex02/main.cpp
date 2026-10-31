#include "PmergeMe.hpp"



/**
 * @brief main - entry point of program .
 * @param [in] argc arguments count .
 * @param [in] argv array of arguments .
 * 
 * @return 0 on success 1 on failure .
*/

int main(int argc, char *argv[])
{
    try
    {
        PmergeMe pm(argv, argc);
        pm.banchMarkVectorList();
        /**
        * NOTE: for detailed comparison between list and vector uncomment or call banchMarkVectorListDetailed method .
        * pm.banchMarkVectorListDetailed();
        **/
    } catch (const PmergeMe::InputException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    catch (const PmergeMe::EmptyException& e)
    {
        std::cout << "Note: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

