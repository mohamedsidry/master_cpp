/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:03:16 by msidry            #+#    #+#             */
/*   Updated: 2026/03/13 14:09:28 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    if (DEBUGMODE)
        std::cout << "Intern Default constructor was called ." << std::endl;
}



Intern::Intern(Intern const & other)
{
    (void)other;
    if (DEBUGMODE)
        std::cout << "Intern Copy constructor was called ." << std::endl;
}

Intern& Intern::operator=(Intern const & other)
{
    (void)other;
    if (DEBUGMODE)
        std::cout << "Intern Copy Assign operator was called ." << std::endl;
    return (*this);
}


Intern::~Intern()
{
    if (DEBUGMODE)
        std::cout << "Intern Destructor was called ." << std::endl;
}


AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    int count;
    AForm * newForm;
    t_form_map forms[] =
    {
        {"shrubbery creation", &Intern::createShrubberyCreation},
        {"robotomy request", &Intern::createRobotomyRequest},
        {"presidential pardon", &Intern::createPresidentialPardon}
    };
    count = sizeof(forms) / sizeof(forms[0]);
    for (int i = 0; i < count; i++)
    {
        if (name == forms[i].name)
        {
            newForm = (this->*forms[i].creator)(target);
            if (!newForm)
                std::cerr << "Intern couldn't allocate " << name << " form !" << std::endl;
            else
                std::cout << "Intern creates " << name << std::endl;
            return (newForm);
        }
    }
    std::cout << "Intern doesn't know how to make " << name << "form ." << std::endl;
    return NULL;
}


AForm * Intern::createShrubberyCreation(std::string const & target)
{
    return (new ShrubberyCreationForm(target));
}

AForm * Intern::createRobotomyRequest(std::string const & target) 
{
    return (new RobotomyRequestForm(target));
}

AForm * Intern::createPresidentialPardon(std::string const & target)
{
    return (new PresidentialPardonForm(target));
}

