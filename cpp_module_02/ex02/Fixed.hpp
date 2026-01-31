#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>


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
        Fixed&  operator=(const Fixed& other);
        Fixed&  operator++();
        Fixed&  operator--();
        Fixed  operator++(int);
        Fixed  operator--(int);
        bool    operator>(const Fixed& right) const;
        bool    operator>=(const Fixed& right) const;
        bool    operator<(const Fixed& right) const;
        bool    operator<=(const Fixed& right) const;
        bool    operator==(const Fixed& right) const;
        bool    operator!=(const Fixed& right) const;
        Fixed   operator*(const Fixed& right) const;
        Fixed   operator/(const Fixed& right)const;
        Fixed   operator+(const Fixed& right) const;
        Fixed   operator-(const Fixed& right)const;

        // MEMBER METHODES
        int toInt(void) const;
        float toFloat(void) const;
        static const Fixed& max(const Fixed &fp1, const Fixed& fp2);
        static Fixed& max(Fixed& fp1, Fixed& fp2);
        static const Fixed& min(const Fixed& fp1, const Fixed& fp2);
        static Fixed& min(Fixed& fp1, Fixed& fp2);

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


// OPERATORS
std::ostream& operator<<(std::ostream& os, const Fixed& obj);


#endif // FIXED_HPP
