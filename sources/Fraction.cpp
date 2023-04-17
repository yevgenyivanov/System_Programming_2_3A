#include "Fraction.hpp"
#include <iostream>
Fraction::Fraction()
{
    this->_numerator = 0;
    this->_denominator = 1;
}
Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
{
    if (_denominator == 0)
    {
        throw std::runtime_error("Denominator cannot be 0!");
    }
    // fractionReduction(); // reduce fraction to minimal value
};
// getter setter
int Fraction::getNumerator()
{
    return this->_numerator;
}
int Fraction::getDenominator()
{
    return this->_denominator;
}
void setNumerator(int) {}
void setDenominator(int) {}

// to be implemented
// helper functions
Fraction Fraction::fractionReduction() { return Fraction(1, 1); }
float Fraction::fractionToFloat() { return 0; }
Fraction Fraction::decimalToFraction(double) { return Fraction(1, 1); }

// arithmetic operators between Fraction obj
Fraction Fraction::operator+(const Fraction &other) const { return Fraction(1, 1); }
Fraction Fraction::operator-(const Fraction &other) const { return Fraction(1, 1); }
Fraction Fraction::operator*(const Fraction &other) const { return Fraction(1, 1); }
Fraction Fraction::operator/(const Fraction &other) const { return Fraction(1, 1); }
// arithmetic operators between Fraction and float
Fraction Fraction::operator+(float decimalNum) const { return Fraction(1, 1); }
Fraction Fraction::operator-(float decimalNum) const { return Fraction(1, 1); }
Fraction Fraction::operator*(float decimalNum) const { return Fraction(1, 1); }
Fraction Fraction::operator/(float decimalNum) const { return Fraction(1, 1); }

// prefix
Fraction &Fraction::operator++()
{
    // to be implemented
    return *this;
}
Fraction &Fraction::operator--()
{
    // to be implemented
    return *this;
}
// postfix (int-s are dummy flags)
Fraction Fraction::operator++(int dummy_flag)
{
    Fraction copy = *this;
    // to be implemented
    return copy;
}
Fraction Fraction::operator--(int dummy_flag)
{
    Fraction copy = *this;
    // to be implemented
    return copy;
}

// comparison operators between Fractions
bool Fraction::operator==(const Fraction &other) const
{
    return false;
}
bool Fraction::operator>(const Fraction &other) const
{
    return false;
}
bool Fraction::operator<(const Fraction &other) const
{
    return false;
}
// will use a combination of the two above fractions
bool Fraction::operator>=(const Fraction &other) const
{
    return (*this > other || *this == other);
}
bool Fraction::operator<=(const Fraction &other) const
{
    return (*this < other || *this == other);
}

// comparison operators between a Fraction and float
bool Fraction::operator==(const float decimalNum) const { return false; }
bool Fraction::operator>(const float decimalNum) const { return false; }
bool Fraction::operator<(const float decimalNum) const { return false; }
bool Fraction::operator>=(const float decimalNum) const{ return false; }
bool Fraction::operator<=(const float decimalNum) const{ return false; }

// same but Fraction is on right side of equation

// friend arithmetic operators for addition, substraction, multiplication, division
Fraction operator+(const float decimalNum, const Fraction &_fraction) { return Fraction(1, 1); }
Fraction operator-(const float decimalNum, const Fraction &_fraction) { return Fraction(1, 1); }
Fraction operator*(const float decimalNum, const Fraction &_fraction) { return Fraction(1, 1); }
Fraction operator/(const float decimalNum, const Fraction &_fraction) { return Fraction(1, 1); }

// friend bool operators
bool operator==(const float decimalNum, const Fraction &_fraction) { return false; }
bool operator>=(const float decimalNum, const Fraction &_fraction) { return false; }
bool operator<=(const float decimalNum, const Fraction &_fraction) { return false; }
bool operator<(const float decimalNum, const Fraction &_fraction) { return false; }
bool operator>(const float decimalNum, const Fraction &_fraction) { return false; }

// friend IO operators for a single fraction
std::ostream &operator<<(std::ostream &output, const Fraction &_fraction)
{
    return (output << _fraction._numerator << '/' << _fraction._denominator << ' ');
}

static std::istream &checkInput(std::istream &input, int expectedInteger)
{
    // int receivedInteger;
    return input;
}

std::istream &operator>>(std::istream &input, Fraction &_fraction)
{
    // int new_numerator, new_denominator;
    return input;
}
