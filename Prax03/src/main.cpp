#include <iostream>
#include "complexnumber.h"

int main() {
    ComplexNumber c1(5,10);
    ComplexNumber c2(c1);      // copy-constructing c2 from c1
    ComplexNumber c3 = std::move(c2);   // move-constructing from an xvalue
    // compiler optimizes into: ComplexNumber c3(std::move(c2));
    ComplexNumber c4 = ComplexNumber(c3);  // move-constructing from an rvalue temporary
    // compiler optimizes into: ComplexNumber c4(ComplexNumber(c3))
    ComplexNumber c5;  c5 = std::move(c1);   // move-assigning from an xvalue, proper assignment
    ComplexNumber c6;  c6 = ComplexNumber(2,2); // move-assigning from an rvalue termporary
    ComplexNumber c7; c7 = c3;    // copy-assigning from another object

    std::cout << "Enter coordinates [real] [imag]: ";
    std::cin >> c4;
    std::cout << "C4 = " << c4 << std::endl;

    std::cout << "C7 = " << c7 << std::endl;
    std::cout << "++C7 = " << ++c7 << std::endl;
    std::cout << "C7++ = " << c7++ << std::endl;
    std::cout << "C7 = " << c7 << std::endl;

    std::cout << "C7 + (10,10) = " << c7 + ComplexNumber(10,10) << std::endl;
    std::cout << "(1,1) + (2,2) + (3,-5) = " << ComplexNumber(1,1) + ComplexNumber(2,2) + ComplexNumber(3,-5) << std::endl;

    std::cout << "C7[0] = " << c7[0] << " and C7[1] = " << c7[1] << std::endl;
    c7[0] = 3; c7[1] = 15;
    std::cout << "The updated C7 is " << c7 << std::endl;

    c7.load("../inputs/complexnumber.xml");
    std::cout << "The updated C7 is " << c7 << std::endl;

    c7.save("../inputs/c7.xml");

    return 0;

}