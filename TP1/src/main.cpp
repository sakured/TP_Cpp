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
    std::cout << std::endl << std::endl << "static_cast<float>(f1) = " << d1 << std::endl;

    Fraction f8 {f1 + 2};
    std::cout << std::endl << "f1 + 2 = " << f8;
    Fraction f9 {f1 - 1};
    std::cout << std::endl << "f1 - 1 = " << f9;
    Fraction f10 {f1 * 2};
    std::cout << std::endl << "f1 * 2 = " << f10;
    Fraction f11 {f1 / 2};
    std::cout << std::endl << "f1 / 2 = " << f11;
    Fraction f12 {2 / f1};
    std::cout << std::endl << "2 / f1 = " << f12;

    Fraction f1_neg { 3, -4 };
    Fraction f2_neg { -1, -2 };
    Fraction f3_neg { -3, 2 };
    std::cout << std::endl << std::endl << "f1_neg = " << f1_neg << std::endl << "f2_neg = " << f2_neg << std::endl << "f3_neg = " << f3_neg << std::endl;
    f1_neg.abs();
    f2_neg.abs();
    f3_neg.abs();
    std::cout << "apres f1_neg.abs() : f1 = " << f1_neg << std::endl;
    std::cout << "apres f2_neg.abs() : f2 = " << f2_neg << std::endl;
    std::cout << "apres f3_neg.abs() : f3 = " << f3_neg << std::endl;

    Fraction f13 {-202, 10};
    int f1_ceil = f1.ceil();
    int f13_ceil = f13.ceil();
    std::cout << std::endl << "f1 = " << f1 << " et f13 = " << f13 << std::endl;
    std::cout << "f1.ceil() = " << f1_ceil << std::endl;
    std::cout << "f13.ceil() = " << f13_ceil << std::endl;
    int f1_floor = f1.floor();
    int f13_floor = f13.floor();
    std::cout << "f1.floor() = " << f1_floor << std::endl;
    std::cout << "f13.floor() = " << f13_floor << std::endl;
    int f1_round = f1.round();
    int f13_round = f13.round();
    std::cout << "f1.round() = " << f1_round << std::endl;
    std::cout << "f13.round() = " << f13_round << std::endl;


    return 0;
}