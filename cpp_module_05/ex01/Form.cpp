#include "Form.hpp"


const std::string Form::DEFAULT_NAME = "DEFAULT_FORM_NAME";
const int Form::DEFAULT_GRADE = 150;

/**
 * @brief Form::Form default constructor .
*/
Form::Form():
name(Form::DEFAULT_NAME),
grade_to_sign(DEFAULT_GRADE),
grade_to_execute(DEFAULT_GRADE),
is_signed(false)
{
    if (DEBUGMODE)
        std::cout << "Form Default constructor was called ." << std::endl;
}


/**
 * @brief Form::Form param constructor .
 * @param [in] name form name .
 * @param [in] gts grade required to signed .
 * @param [in] gte grade required to execute .
*/
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
        std::cout << "Form Param constructor was called ." << std::endl;
}

/**
 * @brief Form::Form copy constructor .
 * @param [in] other form to copy from .
*/
Form::Form(const Form& other):
name(other.name),
grade_to_sign(other.grade_to_sign),
grade_to_execute(other.grade_to_execute),
is_signed(other.is_signed)
{
    if (DEBUGMODE)
        std::cout << "Form Copy constructor was called ." << std::endl;
}


/**
 * @brief Form::Form copy asign constructor .
 * @param [in] other form to copy from .
 * @return form .
*/

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
    if (DEBUGMODE)
        std::cout << "Form Copy Assignment operator was called ." << std::endl;
}

/**
 * @brief Form::~Form destructor .
*/
Form::~Form()
{
    if (DEBUGMODE)
        std::cout << "Form Destructor was called ." << std::endl;
}

/**
 * @brief Form::getName get form name .
 * @return form name .
*/
const std::string& Form::getName(void) const {return (this->name);}

/**
 * @brief Form::getIsSigned check if form signed .
 * @return true or flase .
*/
bool Form::getIsSigned(void) const {return (this->is_signed);}

/**
 * @brief Form::getGradeToSign get grade rquired to sign .
 * @return grade to sign .
*/
int Form::getGradeToSign(void) const {return (this->grade_to_sign);}

/**
 * @brief Form::getGradeToSign get grade rquired to execute .
 * @return grade to execute .
*/
int Form::getGradeToExecute(void) const {return (this->grade_to_execute);}


/**
 * @overide 
 * @brief operator << write form info to output stream.
 * @return output stream .
*/
std::ostream& operator<<(std::ostream& os, const Form& ref)
{
    os << "" << ref.getName() << ", ";
    os << (ref.getIsSigned() ? "is signed" : "is not signed")  << ", ";
    os << "grade required to sign " << ref.getGradeToSign()  << ", ";
    os << "grade required to execute " << ref.getGradeToExecute()  << ".";
    return (os);
}


/**
 * @overide 
 * @brief Form::GradeTooHighException::what return error message .
 * @return error message .
*/
const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High .");
}

/**
 * @overide 
 * @brief Form::GradeTooLowException::what return error message .
 * @return error message .
*/
const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low .");
}

/**
 * @overide 
 * @brief Form::FormAlreadySignedException::what return error message .
 * @return error message .
*/
const char *Form::FormAlreadySignedException::what(void) const throw()
{
    return ("Form is already signed .");
}

/**
 * @brief Form::beSigned try to sign the form by ref throw exception on failure.
 * @param [in] bureaucrat who sign the form .
*/
void Form::beSigned(const Bureaucrat& ref)
{
    if (grade_to_sign < ref.getGrade())
        throw Form::GradeTooLowException();
    if (is_signed)
        throw Form::FormAlreadySignedException();
    is_signed = true;
}
