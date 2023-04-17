#include <iostream>
#include <stdexcept>
#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"

// 4 Tests
TEST_CASE("Correct Initialization")
{
    SUBCASE("General Initialization")
    {
        CHECK_NOTHROW(Fraction(1, 1));
    }
    SUBCASE("Division by 0")
    {
        CHECK_THROWS(Fraction(1, 0)); // cannot divide by 0
    }
    SUBCASE("Reduction")
    {
        CHECK(Fraction(8, 16) == Fraction(1, 2));
    }
    SUBCASE("Non-Reduction")
    {
        Fraction _fraction(8, 9);
        CHECK((_fraction.getNumerator() == 8 &&
               _fraction.getDenominator() == 9));
    }
}
// 11 Tests
TEST_CASE("Comparison")
{
    SUBCASE("Fraction compared to Fraction")
    {
        // Fraction f1(1,3) , f2(5,7), f3(2,6);
        // >
        CHECK((Fraction(1, 3) > Fraction(5, 7)));
        // <
        CHECK((Fraction(50, 100) > Fraction(4, 16)));
        // ==
        // CHECK(Fraction(1,3) == Fraction(63,189));
        // >=
        CHECK((Fraction(5, 9) >= Fraction(3, 11)));
        // <=
        CHECK((Fraction(7, 13) <= Fraction(9, 10)));
    }
    SUBCASE("Fraction compared to float")
    {
        // >
        CHECK((Fraction(3, 5) > 0.3));
        // <
        CHECK((Fraction(11, 33) < 0.4)); // check the reduction is working correctly as well
        // ==
        CHECK((Fraction(5, 19) == 0.263)); // check that 3 digits after decimal are correct (else might be a problem with the processor/memory)
        // >=
        CHECK((Fraction(15, 37) == 0.405)); // check that operator== will return true
        // <=
        CHECK((Fraction(5, 6) <= 0.835));
    }
    SUBCASE("float compared to Fraction")
    {
        // >
        // bool condition =
        CHECK((0.87 > Fraction(2, 3)));
        // <
        CHECK((0.35 < Fraction(5, 8)));
        // ==
        CHECK_FALSE((0.567 == Fraction(1, 3)));
        // >=
        CHECK((0.111 >= Fraction(1, 9)));
        // <=
        CHECK_FALSE((0.78 <= Fraction(7, 10)));
    }
}

// 14 Tests
TEST_CASE("Arithmetic")
{
    SUBCASE("Arithmetic between two Fractions")
    {
        // _fraction + _fraction = ??
        CHECK(Fraction(7, 8) + Fraction(1, 8) == Fraction(1, 1));
        // _fraction - _fraction
        CHECK(Fraction(3, 11) - Fraction(1, 5) == Fraction(4, 55));
        // _fraction * _fraction
        CHECK(Fraction(5, 16) * Fraction(7, 8) == Fraction(35, 128));
        // _fraction / _fraction
        CHECK(Fraction(6, 5) / Fraction(5, 6) == Fraction(36, 25));
    }
    SUBCASE("Prefix")
    {
        Fraction _fractionA_add(4, 5), _fractionA_reduce(10, 4);
        // return then add
        Fraction _fractionB = _fractionA_add++;
        CHECK(_fractionB + 1 == _fractionA_add);
        // return then reduce
        _fractionB = _fractionA_reduce--;
        CHECK(_fractionB - 1 == _fractionA_reduce);
    }
    SUBCASE("Postfix")
    {
        Fraction _fractionA(6, 7);
        CHECK(++_fractionA == Fraction(13, 7));
        Fraction _fractionB(3, 4);
        CHECK(--_fractionB == Fraction(-1, 4));
    }

    SUBCASE("Arithmetic between Fraction and float")
    {
        // _fraction + float
        CHECK(Fraction(1, 3) + 0.666 == Fraction(1, 1));
        // _fraction - float
        CHECK(Fraction(4, 5) - 0.5 == Fraction(3, 10));
        // _fraction * float
        CHECK(Fraction(7, 14) * 0.98 == Fraction(49, 100));
        // _fraction / float
        CHECK(Fraction(15, 27) / 0.956 == Fraction(1250, 2151));
    }
    SUBCASE("Arithmetic between float and Fraction")
    {
        // float + _fraction
        CHECK(0.356 + Fraction(1, 250) == Fraction(9, 25));
        // float - _fraction
        CHECK(0.71 + Fraction(3, 5) == Fraction(11, 100));
        // float * _fraction
        CHECK_FALSE(0.3 * Fraction(1, 100) == Fraction(3, 100));
        // float / _fraction
        CHECK(0.913 / Fraction(51, 67) == Fraction(61171, 51000));
    }
}

TEST_CASE("Input/Output Streams")
{
    SUBCASE("Output")
    {
        std::stringstream _streamstring;
        _streamstring << Fraction(6, 5);
        CHECK(_streamstring.str() == "6/5");
    }
    SUBCASE("Input")
    {
        std::stringstream _streamstring ("3/4");
        Fraction _fraction;
        _streamstring >> _fraction;
        CHECK((_fraction.getNumerator() == 3 && _fraction.getDenominator() == 4));
    }
}