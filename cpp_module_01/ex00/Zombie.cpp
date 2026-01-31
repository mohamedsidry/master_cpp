#include "Zombie.hpp"

#define DEFAULT_NAME "LEET1337"

Zombie::Zombie():
name(DEFAULT_NAME)
{}

Zombie::Zombie(const std::string& name):
name(name)
{
}

Zombie::~Zombie(void)
{
    std::clog << "(debug) : " << name << ": " << "dead !" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
