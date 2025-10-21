#ifndef __HUMANB_HPP
# define __HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB(const std::string& name);
        void attack(void)const;
        void setWeapon(Weapon& weapon);

};


#endif // __HUMANA_HPP