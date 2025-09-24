#include "Harl.hpp"


Harl::Harl(void)
{}

void Harl::debug(void)
{
    std::cout   << "[\033[1;32m DEBUG \033[0m]" 
                << "\n"
                << "\033[3;32mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \nI really do!\033[0m"
                << std::endl;
}


void Harl::info(void)
{
    std::cout   <<  "[\033[1;34m INFO \033[0m]" 
                << "\n"
                << "\033[3;34mI cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m"
                << std::endl;
}

void Harl::warning(void)
{
    std::cout   <<  "[\033[1;33m WARNING \033[0m]"
                << "\n"
                << "\033[3;33mI think I deserve to have some extra bacon for free. \nI’ve been coming for years, whereas you started working here just last month.\033[0m"
                << std::endl;
}


void Harl::error(void)
{
    std::cout   << "[\033[1;31m ERROR \033[0m]"
                << "\n"
                << "\033[3;31mThis is unacceptable! I want to speak to the manager now.\033[0m"
                << std::endl;

}

void Harl::unknown(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;  
}

void Harl::complain(const std::string& level)
{
    int logLevel = mapLogLevel(level);
    enum e_logLevels
    {
        DEBUG = 0,
        INFO = 1,
        WARNING = 2,
        ERROR = 3
    };

    switch (logLevel)
    {
        case DEBUG:
            debug();
            /* fall through */
        case INFO:
            info();
            /* fall through */
        case WARNING:
            warning();
            /* fall through */
        case ERROR:
            error();
            break;
        default:
            unknown();
    }
}


int Harl::mapLogLevel(const std::string& level)
{
    typedef struct s_logLevel
    {
        std::string level;
        int idx;
    } t_logLevel;
    t_logLevel levels[4] = {{"DEBUG", 0}, {"INFO", 1}, {"WARNING", 2}, {"ERROR", 3}};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i].level)
            return levels[i].idx;
    }
    return (-1);
}
