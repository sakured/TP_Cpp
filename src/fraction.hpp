#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
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

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator>(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);