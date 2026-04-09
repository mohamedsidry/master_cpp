#include "PresidentialPardonForm.hpp"


/**
 * @brief PresidentialPardonForm::PresidentialPardonForm default constructor .
*/
PresidentialPardonForm::PresidentialPardonForm():
AForm("presidential pardon", 25, 5),
target("Default")
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm Default constructor was called ." << std::endl;
}

/**
 * @brief PresidentialPardonForm::PresidentialPardonForm param constructor .
 * @param [in] target target name .
*/
PresidentialPardonForm::PresidentialPardonForm(std::string const & target):
AForm("presidential pardon", 25, 5),
target(target)
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm Param constructor was called ." << std::endl;
}

/**
 * @brief PresidentialPardonForm::PresidentialPardonForm copy constructor .
 * @param [in] other form to copy from .
*/
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
AForm(other),
target(other.target)
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm Copy constructor was called ." << std::endl;
}


/**
 * @brief PresidentialPardonForm::operator= copy assign constructor .
 * @param [in] other form to copy from .
*/
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


/**
 * @brief PresidentialPardonForm::PresidentialPardonForm destuctor .
*/
PresidentialPardonForm::~PresidentialPardonForm()
{
    if (DEBUGMODE)
        std::cout << "PresidentialPardonForm destructor was called ." << std::endl;
}



/**
 * @brief PresidentialPardonForm::execute custom execution or throw exception .
 * @param executor bureaucrat to execute the form .
*/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    ReadyToBeExecutedBy(executor);
    std::cout << target
              << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}

