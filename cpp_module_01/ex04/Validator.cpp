#include "Validator.hpp"


bool Validator::isValidParamCount(int argc)
{
    try
    {
        validateParamCount(argc - 1);
        return (true);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (false);
    }
}
void Validator::validateParamCount(int argc)
{
    if (argc != _paramCount)
        throw std::invalid_argument( "Expected " + std::to_string(_paramCount) + " parameters, but got " + std::to_string(argc) + " .");
}
bool  Validator::isValidIO(const char *file)
{
    try
    {
        std::string infile = file;
        std::string outfile = infile + ".replace";
        validateFileStream<std::ifstream>(infile);
        validateFileStream<std::ofstream>(outfile);
        return (true);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error : " << e.what()  << std::endl;
        return (false);
    }
}

bool Validator::validate(int argc, char *argv[])
{
    if (!isValidParamCount(argc))
        return (false);
    if (!isValidIO(argv[1]))
        return (false);
    return (true);
}
