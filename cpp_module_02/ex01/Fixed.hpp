#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPoint;
        static const int bitsFract = 8;
    
    public:
        Fixed();
        Fixed(const int inum);
        Fixed(const float fnum);
        Fixed(const Fixed& other);
        ~Fixed();

        // OPERATORS
        Fixed& operator=(const Fixed& other);
        friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
        // MEMBER METHODES
        
        int toInt(void) const;
        float toFloat(void) const;
        // HELPERS :
        void announce(const std::string& message) const;
        static unsigned int getFloatSign(float num);
        static unsigned int getFloatExponent(float num);
        static unsigned int getFloatMantisaa(float num);
        static std::ostream& showRawBits(unsigned int nbr, size_t len);
        // GETTER && SETTER
        int getRawBits(void) const;
        void setRawBits(const int raw);


};


#endif // FIXED_HPP
