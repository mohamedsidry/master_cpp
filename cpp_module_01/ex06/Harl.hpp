#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <iomanip>


class Harl
{
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void unknown(void);
    int mapLogLevel(const std::string& level);

    public:
        Harl();
        void complain(const std::string& level);
};

#endif //HARL_HPP

