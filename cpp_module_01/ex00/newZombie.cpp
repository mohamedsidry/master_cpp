#include "Zombie.hpp"


Zombie* Zombie::newZombie(std::string name)
{
    Zombie* zombie;
    zombie = NULL;
    try
    {
        zombie = new Zombie(name);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
    return (zombie);
}
