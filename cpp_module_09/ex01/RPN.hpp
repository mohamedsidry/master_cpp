#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <exception>
#include <iostream>
#include <iomanip>
class RPN
{
    static std::string TOKENS;
    private:
        static void add(std::stack<double>& st);
        static void sub(std::stack<double>& st);
        static void mul(std::stack<double>& st);
        static void div(std::stack<double>& st);
        static void execute(std::stack<double>& st, unsigned char op);
    public:
        RPN();
        RPN(const RPN&);
        RPN& operator=(const RPN&);
        ~RPN();

        static void evaluate (const std::string& equation);
        static void evaluate (const char *equation);
};

#endif //RPN_HPP

