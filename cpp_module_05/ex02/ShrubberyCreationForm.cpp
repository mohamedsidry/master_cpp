/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:11:43 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 19:23:43 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>



ShrubberyCreationForm::ShrubberyCreationForm():
AForm("shrubbery", 145, 137),
target("shrubbery")
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Default constructor was called ." << std::endl;
}



ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target):
AForm("shrubbery", 145, 137),
target(target)
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Param constructor was called ." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other):
AForm(other),
target(other.target)
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Copy constructor was called ." << std::endl;
}


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


ShrubberyCreationForm::~ShrubberyCreationForm()
{
    if (DEBUGMODE)
        std::cout << "Shrubbery Destructor was called ." << std::endl;
}


const char *ShrubberyCreationForm::FailedToOpenFileException::what(void) const throw()
{
    return ("Failed to open file for write .");
}





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



