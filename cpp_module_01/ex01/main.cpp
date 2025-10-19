#include "Zombie.hpp"



int main(void)
{
    int idx;
    int count = 10;

    idx = 0;
    Zombie zombie;
    Zombie *zombies = zombie.zombieHorde(count, "zombie");
    Zombie *ptr = zombies;
    if (zombies)
    {
        while (idx < count)
        {
            ptr->announce();
            ptr++;
            idx++;
        }
    }
    delete [] zombies;
    return (0);
}
