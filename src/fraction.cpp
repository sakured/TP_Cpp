#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

/** 
 * Affichage de la fraction
*/

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << '/' << f.denominator;
}

/** 
 * Opérateurs et opérations d'affectation
*/

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

void operator+=(Fraction & f1, Fraction const& f2) {
    Fraction f {f1 + f2};
    f1.numerator = f.numerator;
    f1.denominator = f.denominator;
}

Fraction operator+(Fraction const& f1, int const& i) {
    return simplify({
        f1.numerator + i * f1.denominator,
        f1.denominator
    });
}

Fraction operator+(int const& i, Fraction const& f1) {
    return f1 + i;
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

void operator-=(Fraction & f1, Fraction const& f2) {
    Fraction f {f1 - f2};
    f1.numerator = f.numerator;
    f1.denominator = f.denominator;
}

Fraction operator-(Fraction const& f1, int const& i) {
    return simplify({
        f1.numerator - i * f1.denominator,
        f1.denominator
    });
}

Fraction operator-(int const& i, Fraction const& f1) {
    return f1 - i;
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

void operator*=(Fraction & f1, Fraction const& f2) {
    Fraction f {f1 * f2};
    f1.numerator = f.numerator;
    f1.denominator = f.denominator;
}

Fraction operator*(Fraction const& f1, int const& i) {
    return simplify({
        f1.numerator * i,
        f1.denominator
    });
}

Fraction operator*(int const& i, Fraction const& f1) {
    return f1 * i;
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

void operator/=(Fraction & f1, Fraction const& f2) {
    Fraction f {f1 / f2};
    f1.numerator = f.numerator;
    f1.denominator = f.denominator;
}

Fraction operator/(Fraction const& f1, int const& i) {
    return simplify({
        f1.numerator,
        f1.denominator * i
    });
}

Fraction operator/(int const& i, Fraction const& f1) {
    Fraction f {f1.denominator, f1.numerator};
    return f * i;
}

/** 
 * Test d'égalité et d'inégalité
*/

bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction f1s {simplify({f1.numerator, f1.denominator})};
    Fraction f2s {simplify({f2.numerator, f2.denominator})};
    return (f1s.numerator == f2s.numerator) && (f1s.denominator == f2s.denominator);
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1==f2);
}

/** 
 * Comparaisons
*/

bool operator>(Fraction const& f1, Fraction const& f2) {
    return (f1.numerator * f2.denominator > f2.numerator * f1.denominator);
}

bool operator<(Fraction const& f1, Fraction const& f2) {
    return (f1.numerator * f2.denominator < f2.numerator * f1.denominator);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return (f1.numerator * f2.denominator >= f2.numerator * f1.denominator);
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return (f1.numerator * f2.denominator <= f2.numerator * f1.denominator);
}

/** 
 * Conversion de la fraction en flottant
*/

Fraction::operator float() const {
    return static_cast<float>(this->numerator) / static_cast<float>(this->denominator);
}

/** 
 * Valeur absolue de la fraction
*/

void Fraction::abs() {
    if (static_cast<float>(this->numerator) < 0) {
        this->numerator = -this->numerator;
    }
    if (static_cast<float>(this->denominator) < 0) {
        this->denominator = -this->denominator;
    }
}

/** 
 * Arrondis de la fraction
*/

int Fraction::ceil() {
    if (this->numerator * this->denominator > 0) {
        return static_cast<int>(static_cast<float>(*this)) +1;
    }
    return 1*static_cast<int>(static_cast<float>(*this));
}

int Fraction::floor() {
    if (this->numerator * this->denominator > 0) {
        return static_cast<int>(static_cast<float>(*this));
    }
    return 1*static_cast<int>(static_cast<float>(*this)) -1;
}

int Fraction::round() {
    if (this->numerator % this->denominator > 0.5 * this->denominator) {
        return (*this).ceil();
    }
    return (*this).floor();
}