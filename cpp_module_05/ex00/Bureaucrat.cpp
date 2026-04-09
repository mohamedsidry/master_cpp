#include "Bureaucrat.hpp"


const std::string Bureaucrat::DEFAULT_NAME = "DEFAULT_BUREAUCRAT_NAME";
const int Bureaucrat::DEFAULT_GRADE = 150;

/**
 * @brief Bureaucrat::Bureaucrat default constructor .
*/
Bureaucrat::Bureaucrat():
name(Bureaucrat::DEFAULT_NAME),
grade(Bureaucrat::DEFAULT_GRADE)
{
    if (DEBUGMODE)
        std::cout << "Bureaucrat default constructor was called ." << std::endl;
}



/**
 * @brief Bureaucrat::Bureaucrat constructor with params .
 * @param [in] name bureaucrat name .
 * @param [in] grade bureaucrat grade .
*/
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

/**
 * @brief Bureaucrat::Bureaucrat constructor copy .
 * @param [in] other bureaucrat to copy from .
*/
Bureaucrat::Bureaucrat(const Bureaucrat& other):
name(other.name),
grade(other.grade)
{
    if (DEBUGMODE)
        std::cout << "Bureaucrat copy constructor was called ." << std::endl;
}


/**
 * @brief Bureaucrat::Bureaucrat constructor copy assign .
 * @param [in] other bureaucrat to copy from .
 * @return bureaucrat .
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    if (DEBUGMODE)
        std::cout << "Bureaucrat copy assignment operator was called ." << std::endl;
    return (*this);
}

/**
 * @brief Bureaucrat::~Bureaucrat destructor .
*/
Bureaucrat::~Bureaucrat()
{
    if (DEBUGMODE)
        std::cout << "Bureaucrat destructor was called ." << std::endl;
}





/**
 * @brief Bureaucrat::getName get bureaucrat name .
 * @return bureaucrat name .
*/
const std::string& Bureaucrat::getName(void) const {return (this->name);}

/**
 * @brief Bureaucrat::getGrade get bureaucrat grade .
*/
int Bureaucrat::getGrade(void) const {return (this->grade);}


/**
 * @brief Bureaucrat::increase increase bureaucrat grade or throw exception if pass max grade .
*/
void Bureaucrat::increase(void)
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;    
}

/**
 * @brief Bureaucrat::decrease decrease bureaucrat grade or throw exception if pass min grade .
*/
void Bureaucrat::decrease(void)
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

/**
 * @overide 
 * @brief Bureaucrat::GradeTooHighException::what return error message .
 * @return error message .
*/
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High .");
}

/**
 * @overide 
 * @brief Bureaucrat::GradeTooLowException::what return error message .
 * @return error message .
*/
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low .");
}

/**
 * @overide 
 * @brief operator << write bureaucrat info to output stream.
 * @return output stream .
*/
std::ostream& operator << (std::ostream& os, const Bureaucrat& ref)
{
    return (os << ref.getName() << ", bureaucrat grade " << ref.getGrade());
}
