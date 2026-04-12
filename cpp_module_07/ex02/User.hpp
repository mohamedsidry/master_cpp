#ifndef USER_HPP

#define USER_HPP

#include <iostream>
#include "Array.hpp"


class User
{

    private:
        std::string fname_;
        std::string lname_;
        std::string mail_;
        unsigned int uid_;
        Array<std::string> skills_;
    public:

        User();
        User(const User&);
        User(const std::string&, const std::string&, const std::string&, Array<std::string>&);
        User& operator=(const User&);
        ~User();

        std::string getFullName(void) const;
        const std::string& getFirstName(void) const;
        const std::string& getLastName(void) const;
        const std::string& getMail(void) const;
        unsigned int getUID(void) const;
        const Array<std::string>& getSkills(void) const;
        Array<std::string>& getSkills(void);

        void setFirstName(const std::string& fname);
        void setLastName(const std::string& lname);
        void setMail(const std::string& mail);
        static unsigned int NEXT_USER_ID;
};


std::ostream & operator<<(std::ostream& , const User&); 

#endif //USER_HPP


