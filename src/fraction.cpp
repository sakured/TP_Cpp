#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << '/' << f.denominator;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction f1s {simplify({f1.numerator, f1.denominator})};
    Fraction f2s {simplify({f2.numerator, f2.denominator})};
    return (f1s.numerator == f2s.numerator) && (f1s.denominator == f2s.denominator);
}