#include "Base.hpp"
#include <ctime>

/**
 * @brief main - program entry point .
 * @return 0 on success exit code in failure.
*/
int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Base *ptr = generate();
        Base &ref = *ptr;
        identify(ptr);
        identify(ref);
        delete ptr;
    }
    return (0);
}

