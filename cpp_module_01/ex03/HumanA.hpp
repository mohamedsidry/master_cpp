#ifndef __HUMANA_HPP
# define __HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;

    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack(void)const;

};


#endif // __HUMANA_HPP