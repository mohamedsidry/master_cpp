/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:21:26 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 19:37:10 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


const std::string Form::DEFAULT_NAME = "DEFAULT_FORM_NAME";
const int Form::DEFAULT_GRADE = 150;

Form::Form():
name(Form::DEFAULT_NAME),
grade_to_sign(DEFAULT_GRADE),
grade_to_execute(DEFAULT_GRADE),
is_signed(false)
{
    if (DEBUGMODE)
        std::cout << "Form Default constructor was called !" << std::endl;
}



Form::Form(const std::string& name, const int gts, const int gte):
name(name),
grade_to_sign(gts),
grade_to_execute(gte),
is_signed(false)
{
    if (gts > 150 || gte > 150)
        throw Form::GradeTooLowException();
    if (gts < 1 || gte < 1)
        throw Form::GradeTooHighException();
    if (DEBUGMODE)
        std::cout << "Form Param constructor was called !" << std::endl;
}

Form::Form(const Form& other):
name(other.name),
grade_to_sign(other.grade_to_sign),
grade_to_execute(other.grade_to_execute),
is_signed(other.is_signed)
{
    if (DEBUGMODE)
        std::cout << "Form Copy constructor was called !" << std::endl;
}



Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
    if (DEBUGMODE)
        std::cout << "Form Copy Assignment operator was called !" << std::endl;
}


Form::~Form()
{
    if (DEBUGMODE)
        std::cout << "Form Destructor was called !" << std::endl;
}


const std::string& Form::getName(void) const {return (this->name);}
bool Form::getIsSigned(void) const {return (this->is_signed);}
int Form::getGradeToSign(void) const {return (this->grade_to_sign);}
int Form::getGradeToExecute(void) const {return (this->grade_to_execute);}

std::ostream& operator<<(std::ostream& os, const Form& ref)
{
    os << "" << ref.getName() << ", ";
    os << (ref.getIsSigned() ? "is signed" : "is not signed")  << ", ";
    os << "grade required to sign " << ref.getGradeToSign()  << ", ";
    os << "grade required to execute " << ref.getGradeToExecute()  << ".";
    return (os);
}


const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High .");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low .");
}


const char *Form::FormAlreadySignedException::what(void) const throw()
{
    return ("Form is already signed .");
}


void Form::beSigned(const Bureaucrat& ref)
{
    if (grade_to_sign < ref.getGrade())
        throw Form::GradeTooLowException();
    if (is_signed)
        throw Form::FormAlreadySignedException();
    is_signed = true;
}
