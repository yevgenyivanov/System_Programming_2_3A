#include <iostream>

class Fraction
{
private:
    int _numerator;
    int _denominator;

public:
    Fraction(); //empty constructor will declare 0
    Fraction(int, int);
    // getter setter
    int getNumerator();
    int getDenominator();
    // void setNumerator(int);
    // void setDenominator(int);
    // helper functions
    // fraction reduction func
    Fraction fractionReduction();
    // fraction converters
    float fractionToFloat();
    Fraction decimalToFraction(double);

    //
    // arithmetic operators between Fraction obj
    Fraction operator+(const Fraction &) const;
    Fraction operator-(const Fraction &) const;
    Fraction operator*(const Fraction &) const;
    Fraction operator/(const Fraction &) const;
    // arithmetic operators between Fraction and float
    Fraction operator+(float) const;
    Fraction operator-(float) const;
    Fraction operator*(float) const;
    Fraction operator/(float) const;

    // prefix
    Fraction &operator++();
    Fraction &operator--();
    // postfix (int-s are dummy flags)
    Fraction operator++(int);
    Fraction operator--(int);

    // comparison operators between Fractions
    bool operator==(const Fraction &) const;
    bool operator>(const Fraction &) const;
    bool operator<(const Fraction &) const;
    // will use a combination of the two above fractions
    bool operator>=(const Fraction &) const;
    bool operator<=(const Fraction &) const;

    // comparison operators between a Fraction and float
    bool operator==(float) const;
    bool operator>(float) const;
    bool operator<(float) const;
    bool operator>=(float) const;
    bool operator<=(float) const;

    // friend arithmetic operators for addition, substraction, multiplication, division
    friend Fraction operator+(float, const Fraction &);
    friend Fraction operator-(float, const Fraction &);
    friend Fraction operator*(float, const Fraction &);
    friend Fraction operator/(float, const Fraction &);

    // friend bool operators
    friend bool operator==(float, const Fraction &);
    friend bool operator>=(float, const Fraction &);
    friend bool operator<=(float, const Fraction &);
    friend bool operator<(float, const Fraction &);
    friend bool operator>(float, const Fraction &);

    // friend IO operators for a single fraction
    friend std::ostream &operator<<(std::ostream &, const Fraction &);
    friend std::istream &operator>>(std::istream &, Fraction &);
};
namespace ariel
{
};

