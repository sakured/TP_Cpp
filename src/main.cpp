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
    (f1!=f2) ? std::cout << std::endl << "f1 != f2 : true" : std::cout << std::endl << "f1 != f2 : false";
    (f1!=f7) ? std::cout << std::endl << "f1 != f7 : true" : std::cout << std::endl << "f1 != f7 : false";

    std::cout << std::endl;
    (f1>f2) ? std::cout << std::endl << "f1 > f2 : true" : std::cout << std::endl << "f1 > f2 : false";
    (f1<f2) ? std::cout << std::endl << "f1 < f2 : true" : std::cout << std::endl << "f1 < f2 : false";
    (f1>=f2) ? std::cout << std::endl << "f1 >= f2 : true" : std::cout << std::endl << "f1 >= f2 : false";
    (f1<=f1) ? std::cout << std::endl << "f1 <= f1 : true" : std::cout << std::endl << "f1 <= f1 : false";

    std::cout << std::endl;
    f1 += f2;
    std::cout << std::endl << "apres f1 += f2 : f1 = " << f1;
    f1 -= f2;
    std::cout << std::endl << "apres f1 -= f2 : f1 = " << f1;
    f1 *= f2;
    std::cout << std::endl << "apres f1 *= f2 : f1 = " << f1;
    f1 /= f2;
    std::cout << std::endl << "apres f1 /= f2 : f1 = " << f1;

    float d1 {static_cast<float>(f1)}; 
    std::cout << std::endl << std::endl << "static_cast<float>(f1) = " << d1 << std::endl << std::endl;

    Fraction f8 {f1 + 2};
    std::cout << std::endl << "f1 + 2 = " << f8;
    Fraction f9 {f1 - 1};
    std::cout << std::endl << "f1 - 2 = " << f9;
    Fraction f10 {f1 * 2};
    std::cout << std::endl << "f1 * 2 = " << f10;

    return 0;
}