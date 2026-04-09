#include "ShrubberyCreationForm.hpp"
#include <fstream>


/**
 * @brief ShrubberyCreationForm::ShrubberyCreationForm default constructor .
*/
ShrubberyCreationForm::ShrubberyCreationForm():
AForm("shrubbery creation", 145, 137),
target("Default")
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Default constructor was called ." << std::endl;
}


/**
 * @brief ShrubberyCreationForm::ShrubberyCreationForm param constructor .
 * @param [in] target target name .
*/
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target):
AForm("shrubbery creation", 145, 137),
target(target)
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Param constructor was called ." << std::endl;
}

/**
 * @brief ShrubberyCreationForm::ShrubberyCreationForm copy constructor .
 * @param [in] other form to copy from .
*/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other):
AForm(other),
target(other.target)
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Copy constructor was called ." << std::endl;
}

/**
 * @brief ShrubberyCreationForm::operator= copy assign constructor .
 * @param [in] other form to copy from .
*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    if (DEBUGMODE)
        std::cout << "Shrubbery Copy Assignment operator was called ." << std::endl;
    return (*this);
}

/**
 * @brief ShrubberyCreationForm::ShrubberyCreationForm destuctor .
*/
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Destructor was called ." << std::endl;
}

/**
 * @overide 
 * @brief ShrubberyCreationForm::FailedToOpenFileException::what return error message .
 * @return error message .
*/
const char *ShrubberyCreationForm::FailedToOpenFileException::what(void) const throw()
{
    return ("Failed to open file for write .");
}


/**
 * @brief ShrubberyCreationForm::execute custom execution or throw exception .
 * @param executor bureaucrat to execute the form .
*/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    ReadyToBeExecutedBy(executor);

    static const char *tree[] = {
        "   /\\   ",
        "  /**\\  ",
        " /****\\ ",
        "/******\\",
        "   ||   "
    };

    std::ofstream file(target + "_shrubbery");
    if (!file.is_open())
        throw ShrubberyCreationForm::FailedToOpenFileException();
    for (int row = 0; row < 5; row++)
    {
        for (int t = 0; t < 10; t++)
            file << tree[row] << " ";
        file << std::endl;
    }

    file.close();
}



