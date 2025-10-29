#include "main.hpp"



int main(int argc , char *argv[])
{
    if (Validator::validate(argc, argv) == false)
        return (EXIT_FAILURE);
    Replace::fileReplace(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
    return (EXIT_SUCCESS);
}
