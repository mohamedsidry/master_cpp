#include <iostream>
#include "HumanB.hpp"


HumanB::HumanB(const std::string& name):
name(name),
weapon(NULL)
{}

void HumanB::attack(void)const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
    weapon = &newWeapon;
}
