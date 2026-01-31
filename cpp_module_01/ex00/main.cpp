# include "Zombie.hpp"


int main(void)
{
    Zombie zombie1("ZOMBIE_1");
    zombie1.announce();
    Zombie *zombie2ptr = zombie1.newZombie("ZOMBIE_2");
    if (zombie2ptr)
        zombie2ptr->announce();
    (*zombie2ptr).randomChump("ZOMBIE_3");
    Zombie zombie4;
    zombie4.announce();
    delete zombie2ptr;
}
