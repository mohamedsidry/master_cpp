#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedPoint;
        static const int bitsFract = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        
        //GETTER && SETTER

        int getRawBits(void) const;
        void setRawBits(const int raw);
        void announce(const std::string& message) const;


};


#endif // FIXED_HPP
