#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon();
        Weapon(const std::string& type);
        const std::string& getType(void) const;
        void setType(const std::string& value);

};


#endif // WEAPON_HPP