#include <iostream>
#include "HumanA.hpp"


HumanA::HumanA(const std::string& name, Weapon& wp):
name(name),
weapon(wp)
{}

void HumanA::attack(void)const
{
    std::cout << name + " attacks with their " + weapon.getType() << std::endl;
}
