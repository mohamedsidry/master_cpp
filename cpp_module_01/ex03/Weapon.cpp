
#include "Weapon.hpp"


Weapon::Weapon():
type("Default Weapon"){}
Weapon::Weapon(const std::string& type):
type(type){}

// GETTERS
const std::string& Weapon::getType(void) const{return (type);}

// SETTERS
void Weapon::setType(const std::string& value){type = value;}




