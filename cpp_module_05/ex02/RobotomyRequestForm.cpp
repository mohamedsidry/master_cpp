/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:37:26 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 19:23:41 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm():
AForm("Robo", 72, 45),
target("Robo")
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Default constructor was called ." << std::endl;
}




RobotomyRequestForm::RobotomyRequestForm(std::string const & target):
AForm("Robo", 72, 45),
target(target)
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Param constructor was called ." << std::endl;
}



RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other):
AForm(other),
target(other.target)
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Copy constructor was called ." << std::endl;
}


RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Copy Assign operator was called ." << std::endl;
    return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm()
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Destructor was called ." << std::endl;
}



void RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
    ReadyToBeExecutedBy(executor);   
    std::cout << "Bzzzzzzzzz... drilling noises..." << std::endl;
    srand(time(0));

    if (rand() % 2)
        std::cout << target << " has been robotomized successfully ." << std::endl;
    else
        std::cout << "robotomy failed ." << std::endl;
}

