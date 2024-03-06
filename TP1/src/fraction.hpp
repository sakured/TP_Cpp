#pragma once
#include <iostream>

struct Fraction {
    int numerator;
    int denominator;

    operator float() const;
    void abs();
    int ceil();
    int floor();
    int round();
};

std::ostream& operator<<(std::ostream& os, Fraction const& f);

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

void operator+=(Fraction & f1, Fraction const& f2);
void operator-=(Fraction & f1, Fraction const& f2);
void operator*=(Fraction & f1, Fraction const& f2);
void operator/=(Fraction & f1, Fraction const& f2);

Fraction operator+(Fraction const& f1, int const& i);
Fraction operator+(int const& i, Fraction const& f1);
Fraction operator-(Fraction const& f1, int const& i);
Fraction operator-(int const& i, Fraction const& f1);
Fraction operator*(Fraction const& f1, int const& i);
Fraction operator*(int const& i, Fraction const& f1);
Fraction operator/(Fraction const& f1, int const& i);
Fraction operator/(int const& i, Fraction const& f1);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator>(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);