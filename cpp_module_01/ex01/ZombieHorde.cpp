#include "Zombie.hpp"


Zombie* Zombie::zombieHorde(int N, std::string name)
{
    Zombie *zombies;
    int idx;

    zombies = NULL;
    idx = 0;
    if (N <= 0)
        return (NULL);
    try 
    {
        zombies = new Zombie[N];
        while (idx < N)
        {
            zombies[idx].setName(name);
            idx++;
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
    return (zombies);
}
