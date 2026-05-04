#include "RPN.hpp"





/**
 * @brief main - entry point of program .
 * @param [in] argc arguments count .
 * @param [in] argv array of arguments .
 * 
 * @return 0 on success 1 on failure .
*/
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "Error : invalid program arguments '" << argv[0] << " `expretion`'" << std::endl;
        return (1);
    }
    try
    {
        RPN nn;
        RPN::evaluate(argv[1]);
        nn.evaluate(argv[1]);
    } catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}

