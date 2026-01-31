#include "Zombie.hpp"

#define DEFAULT_NAME "LEET1337"

Zombie::Zombie():
name(DEFAULT_NAME)
{}

Zombie::Zombie(std::string name):
name(name)
{}


Zombie::~Zombie()
{
    std::clog << "(debug) : " + name + " : dead !" << std::endl;  
}


void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// SETTERS


void Zombie::setName(const std::string& value){name = value;}
