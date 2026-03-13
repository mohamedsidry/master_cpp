/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:21:26 by msidry            #+#    #+#             */
/*   Updated: 2026/03/11 16:29:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


const std::string AForm::DEFAULT_NAME = "DEFAULT_AForm_NAME";
const int AForm::DEFAULT_GRADE = 150;

AForm::AForm():
name(AForm::DEFAULT_NAME),
grade_to_sign(DEFAULT_GRADE),
grade_to_execute(DEFAULT_GRADE),
is_signed(false)
{
    if (DEBUGMODE)
        std::cout << "Base Form Default constructor was called ." << std::endl;
}



AForm::AForm(const std::string& name, const int gts, const int gte):
name(name),
grade_to_sign(gts),
grade_to_execute(gte),
is_signed(false)
{
    if (gts > 150 || gte > 150)
        throw AForm::GradeTooLowException();
    if (gts < 1 || gte < 1)
        throw AForm::GradeTooHighException();
    if (DEBUGMODE)
        std::cout << "Base Form Param constructor was called ." << std::endl;
}

AForm::AForm(const AForm& other):
name(other.name),
grade_to_sign(other.grade_to_sign),
grade_to_execute(other.grade_to_execute),
is_signed(other.is_signed)
{
    if (DEBUGMODE)
        std::cout << "Base Form Copy constructor was called ." << std::endl;
}



AForm& AForm::operator=(const AForm& other)
{
    if (DEBUGMODE)
        std::cout << "Base Form Copy Assignment operator was called ." << std::endl;
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}


AForm::~AForm()
{
    if (DEBUGMODE)
        std::cout << "AForm Destructor was called ." << std::endl;
}


const std::string& AForm::getName(void) const {return (this->name);}
bool AForm::getIsSigned(void) const {return (this->is_signed);}
int AForm::getGradeToSign(void) const {return (this->grade_to_sign);}
int AForm::getGradeToExecute(void) const {return (this->grade_to_execute);}

std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
    os << ref.getName() << ", ";
    os << (ref.getIsSigned() ? "is signed" : "is not signed")  << ", ";
    os << "grade required to sign " << ref.getGradeToSign()  << ", ";
    os << "grade required to execute " << ref.getGradeToExecute()  << ".";
    return (os);
}


const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High .");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low .");
}


const char *AForm::FormAlreadySignedException::what(void) const throw()
{
    return ("Form is already signed .");
}


const char *AForm::FormIsNotSignedException::what(void) const throw()
{
    return ("Form is not signed yet .");
}

void AForm::beSigned(const Bureaucrat& ref)
{
    if (is_signed)
        throw AForm::FormAlreadySignedException();
    if (grade_to_sign < ref.getGrade())
        throw AForm::GradeTooLowException();
    is_signed = true;
}


bool AForm::ReadyToBeExecutedBy(const Bureaucrat &executor) const
{
    if (!is_signed)
        throw FormIsNotSignedException();
    if (executor.getGrade() > grade_to_execute)
        throw GradeTooLowException();
    return (true);
}

