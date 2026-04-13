#include "User.hpp"



unsigned int User::NEXT_USER_ID = 1;

User::User():
fname_("Unknown"),
lname_("Unknown"),
mail_("Unknown"),
uid_(User::NEXT_USER_ID),
skills_(Array<std::string>(10))
{
    User::NEXT_USER_ID++;
}



User::User(const User& other):
fname_(other.fname_),
lname_(other.lname_),
mail_(other.mail_),
uid_(User::NEXT_USER_ID),
skills_(Array<std::string>(other.skills_))
{
    User::NEXT_USER_ID++;
}



User::User(const std::string& fn, const std::string& ln, const std::string& em, Array<std::string>& skills):
fname_(fn),
lname_(ln),
mail_(em),
uid_(User::NEXT_USER_ID),
skills_(Array<std::string>(skills))
{
    User::NEXT_USER_ID++;
}




User& User::operator=(const User& other)
{
    if (this != &other)
    {
        this->fname_ = other.fname_;
        this->lname_ = other.lname_;
        this->mail_ = other.mail_;
        this->skills_ = other.skills_;
    }
    return (*this);
}


User::~User()
{
}


const std::string& User::getFirstName(void) const
{
    return this->fname_;
}

const std::string& User::getLastName(void) const 
{
    return this->lname_;
}


std::string User::getFullName(void) const
{
    return this->fname_ + this->lname_;
}

const std::string& User::getMail(void) const
{
    return this->mail_;
}


unsigned int User::getUID(void) const 
{
    return this->uid_;
}


const Array<std::string>& User::getSkills(void) const
{
    return this->skills_;
}



Array<std::string>& User::getSkills(void)
{
    return this->skills_;
}


void User::setFirstName(const std::string& fname)
{
    this->fname_ = fname;
}


void User::setLastName(const std::string& lname)
{
    this->lname_  = lname;
}


void User::setMail(const std::string& mail)
{
    this->mail_ = mail;
}





std::ostream& operator<<(std::ostream& os, const User&user)
{
    os << "Uid : " << user.getUID() << std::endl;
    os << "First Name : " << user.getFirstName() << std::endl;
    os << "Last Name : " << user.getLastName() << std::endl;
    os << "Email : " << user.getMail() << std::endl;
    os << "Skills : " << "[";
    for (unsigned int i = 0; i < user.getSkills().size(); i++)
        os << user.getSkills()[i] << (i < user.getSkills().size() - 1 ? ", " : "] .");
    os << std::endl;
    return os;
}

