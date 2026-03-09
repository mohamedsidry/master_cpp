/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:30:51 by msidry            #+#    #+#             */
/*   Updated: 2026/03/09 15:50:43 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat():
name("Default"),
grade(150)
{
    std::cout << "Bureaucrat default constructor was called ." << std::endl;
}



Bureaucrat::Bureaucrat(const std::string& name, int grade):
name(name),
grade(grade)
{
    if (grade  < 1)
        throw  GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat param constructor was called ." << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other):
name(other.name),
grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor was called ." << std::endl;
}



Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    std::cout << "Bureaucrat copy assignment operator was called ." << std::endl;
    return (*this);
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor was called ." << std::endl;
}






const std::string& Bureaucrat::getName(void) const {return (this->name);}

int Bureaucrat::getGrade(void) const {return (this->grade);}




void Bureaucrat::increase(void)
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;    
}
void Bureaucrat::decrease(void)
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}




std::ostream& operator << (std::ostream& os, const Bureaucrat& ref)
{
    return (os << ref.getName() << ", bureaucrat grade " << ref.getGrade());
}
