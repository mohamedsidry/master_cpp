#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/**
 * @brief Intern::Intern default constructor .
*/
Intern::Intern()
{
    if (DEBUGMODE)
        std::cout << "Intern Default constructor was called ." << std::endl;
}

/**
 * @brief Intern::Intern copy constructor .
 * @param [in] other  no need to update this but e Orthodox Canonical Form .
*/
Intern::Intern(Intern const & other)
{
    (void)other;
    if (DEBUGMODE)
        std::cout << "Intern Copy constructor was called ." << std::endl;
}

/**
 * @brief Intern::Intern copy assign constructor .
 * @param [in] other  no need to update this but e Orthodox Canonical Form .
 * @return intern .
*/
Intern& Intern::operator=(Intern const & other)
{
    (void)other;
    if (DEBUGMODE)
        std::cout << "Intern Copy Assign operator was called ." << std::endl;
    return (*this);
}

/**
 * @brief Intern::~Intern default destructor .
*/
Intern::~Intern()
{
    if (DEBUGMODE)
        std::cout << "Intern Destructor was called ." << std::endl;
}

/**
 * @brief Intern::makeForm create well known form .
 * @param [in] name  form name .
 * @param [in] target  form target .
 * @return form or null on failure .
*/
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


/**
 * @brief Intern::createShrubberyCreation create Shrubbery form .
 * @param [in] target  form target .
 * @return form or null on failure .
*/
AForm * Intern::createShrubberyCreation(std::string const & target)
{
    return (new ShrubberyCreationForm(target));
}

/**
 * @brief Intern::createRobotomyRequest create RobotomyRequest form .
 * @param [in] target  form target .
 * @return form or null on failure .
*/
AForm * Intern::createRobotomyRequest(std::string const & target) 
{
    return (new RobotomyRequestForm(target));
}

/**
 * @brief Intern::createPresidentialPardon create PresidentialPardon form .
 * @param [in] target  form target .
 * @return form or null on failure .
*/
AForm * Intern::createPresidentialPardon(std::string const & target)
{
    return (new PresidentialPardonForm(target));
}

