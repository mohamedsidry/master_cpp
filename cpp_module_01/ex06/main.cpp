#include "Harl.hpp"



int main(int argc, char *argv[])
{
    Harl ha;

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return (1);
    }
    ha.complain(std::string(argv[1]));
    return (0);
}
