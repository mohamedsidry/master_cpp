#include "RPN.hpp"



std::string RPN::TOKENS = "+-/*";
/**
 * @brief RPN default constructor .
*/
RPN::RPN()
{}



/**
 * @brief RPN copy constructor .
 * @param [in] other object.
*/
RPN::RPN(const RPN& other)
{
    (void)other;
}



/**
 * @brief RPN copy assign constructor .
 * @param [in] other object.
*/
RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

/**
 * @brief RPN destructor .
*/
RPN::~RPN()
{}



void RPN::evaluate(const std::string& exp)
{
    evaluate(exp.c_str());
}

void RPN::evaluate(const char *exp)
{
    std::stack<double> vals;
    if (!exp)
        throw std::runtime_error("Empty expression");
    for (int i = 0; exp[i]; i++)
    {
        if (std::isspace(exp[i]))
            continue;
        std::string::const_iterator tmp = std::find(RPN::TOKENS.begin(), RPN::TOKENS.end(), exp[i]);
        if (tmp != RPN::TOKENS.end())
            execute(vals, exp[i]);
        else if (std::isdigit(exp[i]))
            vals.push(static_cast<double>(exp[i] - 48));
        else
            throw std::runtime_error("Unexpected token .");
    }
    if (vals.size() != 1)
        throw std::runtime_error("Unbalanced RPN expression.");
    std::cout << std::fixed << std::setprecision(2) << vals.top() << std::endl;
}

void RPN::execute(std::stack<double>& st, unsigned char op)
{
    switch (op)
    {
        case '+':
            RPN::add(st);
            break;
        case '-':
            RPN::sub(st);
            break;
        case '*':
            RPN::mul(st);
            break;
        case '/':
            RPN::div(st);
            break;
    default:
        throw std::runtime_error("Unvalid token expression.");
        break;
    }
}

void RPN::sub(std::stack<double>& st)
{
    if (st.size() == 0)
        throw std::runtime_error("Unbalanced RPN expression.");
    else if (st.size() != 1)
    {
        double left = st.top();
        st.pop();
        double right = st.top();
        st.pop();
        st.push(right - left);
    }
    else
    {
        double val1 = st.top();
        st.pop();
        st.push(val1 * -1);
    }
}

void RPN::add(std::stack<double>& st)
{
    if (st.size() == 0)
        throw std::runtime_error("Unbalanced RPN expression.");
    else if (st.size() != 1)
    {
        double left = st.top();
        st.pop();
        double right = st.top();
        st.pop();
        st.push(right + left);
    }
}

void RPN::mul(std::stack<double>& st)
{
    if (st.size() < 2)
        throw std::runtime_error("Unbalanced RPN expression.");
    double left, right;
    right = st.top();
    st.pop();
    left = st.top();
    st.pop();
    st.push(left * right);
}

void RPN::div(std::stack<double>& st)
{
    if (st.size() < 2)
        throw std::runtime_error("Unbalanced aaRPN expression.");
    double left, right;
    right = st.top();
    st.pop();
    left = st.top();
    st.pop();
    if (right == 0)
        throw std::logic_error("Division by 0.");
    st.push(left / right);
}


