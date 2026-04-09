#include "AForm.hpp"



const std::string AForm::DEFAULT_NAME = "DEFAULT_FORM_NAME";
const int AForm::DEFAULT_GRADE = 150;

/**
 * @brief AForm::AForm default constructor .
*/
AForm::AForm():
name(AForm::DEFAULT_NAME),
grade_to_sign(DEFAULT_GRADE),
grade_to_execute(DEFAULT_GRADE),
is_signed(false)
{
    if (DEBUGMODE)
        std::cout << "AForm Default constructor was called ." << std::endl;
}


/**
 * @brief AForm::AForm param constructor .
 * @param [in] name AForm name .
 * @param [in] gts grade required to signed .
 * @param [in] gte grade required to execute .
*/
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
        std::cout << "Form Param constructor was called ." << std::endl;
}

/**
 * @brief AForm::AForm copy constructor .
 * @param [in] other form to copy from .
*/
AForm::AForm(const AForm& other):
name(other.name),
grade_to_sign(other.grade_to_sign),
grade_to_execute(other.grade_to_execute),
is_signed(other.is_signed)
{
    if (DEBUGMODE)
        std::cout << "Form Copy constructor was called ." << std::endl;
}


/**
 * @brief AForm::AForm copy asign constructor .
 * @param [in] other form to copy from .
 * @return form .
*/

AForm& AForm::operator=(const AForm& other)
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
 * @brief AForm::~AForm destructor .
*/
AForm::~AForm()
{
    if (DEBUGMODE)
        std::cout << "Form Destructor was called ." << std::endl;
}

/**
 * @brief AForm::getName get form name .
 * @return form name .
*/
const std::string& AForm::getName(void) const {return (this->name);}

/**
 * @brief AForm::getIsSigned check if form signed .
 * @return true or flase .
*/
bool AForm::getIsSigned(void) const {return (this->is_signed);}

/**
 * @brief AForm::getGradeToSign get grade rquired to sign .
 * @return grade to sign .
*/
int AForm::getGradeToSign(void) const {return (this->grade_to_sign);}

/**
 * @brief AForm::getGradeToSign get grade rquired to execute .
 * @return grade to execute .
*/
int AForm::getGradeToExecute(void) const {return (this->grade_to_execute);}


/**
 * @overide 
 * @brief operator << write form info to output stream.
 * @return output stream .
*/
std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
    os << "" << ref.getName() << ", ";
    os << (ref.getIsSigned() ? "is signed" : "is not signed")  << ", ";
    os << "grade required to sign " << ref.getGradeToSign()  << ", ";
    os << "grade required to execute " << ref.getGradeToExecute()  << ".";
    return (os);
}


/**
 * @overide 
 * @brief AForm::GradeTooHighException::what return error message .
 * @return error message .
*/
const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High .");
}

/**
 * @overide 
 * @brief AForm::GradeTooLowException::what return error message .
 * @return error message .
*/
const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low .");
}

/**
 * @overide 
 * @brief AForm::FormAlreadySignedException::what return error message .
 * @return error message .
*/
const char *AForm::FormAlreadySignedException::what(void) const throw()
{
    return ("Form is already signed .");
}
/**
 * @overide 
 * @brief AForm::FormIsNotSignedException::what return error message .
 * @return error message .
*/
const char *AForm::FormIsNotSignedException::what(void) const throw()
{
    return ("Form is not signed yet .");
}

/**
 * @brief AForm::beSigned try to sign the form by ref throw exception on failure.
 * @param [in] bureaucrat who sign the form .
*/
void AForm::beSigned(const Bureaucrat& ref)
{
    if (grade_to_sign < ref.getGrade())
        throw AForm::GradeTooLowException();
    if (is_signed)
        throw AForm::FormAlreadySignedException();
    is_signed = true;
}


/**
 * @brief AForm::ReadyToBeExecutedBy check if bureaucrat can sign this form .
 * @param [in] bureaucrat who sign the form .
 * @return true or flase .
*/
bool AForm::ReadyToBeExecutedBy(const Bureaucrat &executor) const
{
    if (!is_signed)
        throw FormIsNotSignedException();
    if (executor.getGrade() > grade_to_execute)
        throw GradeTooLowException();
    return (true);
}

