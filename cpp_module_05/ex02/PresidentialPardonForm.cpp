/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:02:28 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 19:23:35 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"




PresidentialPardonForm::PresidentialPardonForm():
AForm("Presidential", 25, 5),
target("Presidential")
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm Default constructor was called ." << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string const & target):
AForm("Presidential", 25, 5),
target(target)
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm Param constructor was called ." << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
AForm(other),
target(other.target)
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm Copy constructor was called ." << std::endl;
}




PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
    if (this != & other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm Copy Assign operator was called ." << std::endl;
    return (*this);
}



PresidentialPardonForm::~PresidentialPardonForm()
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm destructor was called ." << std::endl;
}




void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    ReadyToBeExecutedBy(executor);
    std::cout << target
              << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}

