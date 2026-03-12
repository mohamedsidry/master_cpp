/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:30:51 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 19:37:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


const std::string Bureaucrat::DEFAULT_NAME = "DEFAULT_BUREAUCRAT_NAME";
const int Bureaucrat::DEFAULT_GRADE = 150;

Bureaucrat::Bureaucrat():
name(Bureaucrat::DEFAULT_NAME),
grade(Bureaucrat::DEFAULT_GRADE)
{
    if (DEBUGMODE)
        std::cout << "Bureaucrat default constructor was called ." << std::endl;
}



Bureaucrat::Bureaucrat(const std::string& name, int grade):
name(name),
grade(grade)
{
    if (grade  < 1)
        throw  Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (DEBUGMODE)
        std::cout << "Bureaucrat param constructor was called ." << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other):
name(other.name),
grade(other.grade)
{
    if (DEBUGMODE)
        std::cout << "Bureaucrat copy constructor was called ." << std::endl;
}



Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    if (DEBUGMODE)
        std::cout << "Bureaucrat copy assignment operator was called ." << std::endl;
    return (*this);
}


Bureaucrat::~Bureaucrat()
{
    if (DEBUGMODE)
        std::cout << "Bureaucrat destructor was called ." << std::endl;
}






const std::string& Bureaucrat::getName(void) const {return (this->name);}

int Bureaucrat::getGrade(void) const {return (this->grade);}



void Bureaucrat::increase(void)
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;    
}
void Bureaucrat::decrease(void)
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High .");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low .");
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& ref)
{
    return (os << ref.getName() << ", bureaucrat grade " << ref.getGrade());
}
