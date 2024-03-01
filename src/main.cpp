#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1;
    std::cout << std::endl << "f2 = " << f2;
    std::cout << std::endl << std::endl;

    Fraction f3 {f1 + f2};
    std::cout << "f1 + f2 = " << f3;

    Fraction f4 {f1 - f2};
    std::cout << std::endl << "f1 - f2 = " << f4;

    Fraction f5 {f1 * f2};
    std::cout << std::endl << "f1 * f2 = " << f5;

    Fraction f6 {f1 / f2};
    std::cout << std::endl << "f1 / f2 = " << f6;

    Fraction f7 {6, 8};
    std::cout << std::endl << std::endl << "f7 = " << f7;
    (f1==f2) ? std::cout << std::endl << "f1 == f2 : true" : std::cout << std::endl << "f1 == f2 : false";
    (f1==f7) ? std::cout << std::endl << "f1 == f7 : true" : std::cout << std::endl << "f1 == f7 : false";

    return 0;
}