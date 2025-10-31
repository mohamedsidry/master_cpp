#include "Harl.hpp"



void Harl::debug(void)
{
    std::cout   << std::left << std::setw(20) << "[\033[1;32mDEBUG\033[0m]" 
                << " : "
                << "\033[3;32mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m"
                << std::endl;
}


void Harl::info(void)
{
    std::cout   << std::left << std::setw(20) << "[\033[1;34mINFO\033[0m]" 
                << " : "
                << "\033[3;34mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m"
                << std::endl;
}

void Harl::warning(void)
{
    std::cout   << std::left << std::setw(20) << "[\033[1;33mWARNING\033[0m]"
                << " : "
                << "\033[3;33mI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\033[0m"
                << std::endl;
}


void Harl::error(void)
{
    std::cout   << std::left << std::setw(20) << "[\033[1;31mERROR\033[0m]"
                << " : "
                << "\033[3;31mThis is unacceptable! I want to speak to the manager now.\033[0m"
                << std::endl;

}


void Harl::complain(std::string level)
{
    typedef void (Harl::*callback)(void);

    callback calls[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return (this->*calls[i])();
    }
}
