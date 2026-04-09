#include <iostream>
#include "Serializer.hpp"

/**
 * @brief main - program entry point .
 * @return 0 on success exit code in failure.
*/

int main(void)
{
    Data user;
    user.uid = ~0;
    user.name = "Famas-95";
    std::cout << "\033[1;34m DISPLAY PRE INFO : \033[0m" << std::endl;
    std::cout << "\t user id : " << user.uid << std::endl;
    std::cout << "\t user name : " << user.name << std::endl;
    uintptr_t raw = Serializer::serialize(&user);
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "\033[1;34m DATA POINTER BLOCK MEMORY : \033[0m" << std::endl;
    std::cout << "\t raw : " << raw << std::endl;
    std::cout << "\t pointer : " << ptr << std::endl;
    if (ptr == &user)
        std::cout << "\t user address match ptr" << std::endl;
    std::cout << "\033[1;34m DISPLAY POST INFO : \033[0m" << std::endl;
    std::cout << "\t user id : " << ptr->uid << std::endl;
    std::cout << "\t user name : " << ptr->name << std::endl;
    return (0);
}

