#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(ShrubberyCreationForm const & other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const & other);
        ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const & executor) const ;
        class FailedToOpenFileException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

