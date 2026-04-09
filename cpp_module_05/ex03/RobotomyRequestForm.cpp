#include "RobotomyRequestForm.hpp"


/**
 * @brief RobotomyRequestForm::RobotomyRequestForm default constructor .
*/
RobotomyRequestForm::RobotomyRequestForm():
AForm("robotomy request", 72, 45),
target("Default")
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Default constructor was called ." << std::endl;
}



/**
 * @brief RobotomyRequestForm::RobotomyRequestForm param constructor .
 * @param [in] target target name .
*/
RobotomyRequestForm::RobotomyRequestForm(std::string const & target):
AForm("robotomy request", 72, 45),
target(target)
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Param constructor was called ." << std::endl;
}


/**
 * @brief RobotomyRequestForm::RobotomyRequestForm copy constructor .
 * @param [in] other form to copy from .
*/
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other):
AForm(other),
target(other.target)
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Copy constructor was called ." << std::endl;
}

/**
 * @brief RobotomyRequestForm::operator= copy assign constructor .
 * @param [in] other form to copy from .
*/
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

/**
 * @brief RobotomyRequestForm::RobotomyRequestForm destuctor .
*/
RobotomyRequestForm::~RobotomyRequestForm()
{
    if (DEBUGMODE)
        std::cout << "RobotomyRequestForm Destructor was called ." << std::endl;
}


/**
 * @brief RobotomyRequestForm::execute custom execution or throw exception .
 * @param executor bureaucrat to execute the form .
*/
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

