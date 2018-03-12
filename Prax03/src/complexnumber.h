#ifndef PRAX03_COMPLEXNUMBER_H
#define PRAX03_COMPLEXNUMBER_H

#include <ostream>

class ComplexNumber {
public:
    ComplexNumber() : real(0), imag(0) {}
    ComplexNumber(int real, int imag);
    ComplexNumber(const ComplexNumber& c);
    ComplexNumber(ComplexNumber&& c) noexcept;
    ComplexNumber& operator=(const ComplexNumber& c);
    ComplexNumber& operator=(ComplexNumber&& c) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
    friend std::istream& operator>>(std::istream& is, ComplexNumber& c);
    ComplexNumber& operator++();
    ComplexNumber operator++(int i);
    bool operator==(const ComplexNumber& c);
    friend bool operator<(const ComplexNumber& a, const ComplexNumber& b);
    friend ComplexNumber operator+(ComplexNumber a, const ComplexNumber& b);
    friend ComplexNumber operator-(ComplexNumber a, const ComplexNumber& b);
    friend ComplexNumber operator*(ComplexNumber a, const ComplexNumber& b);
    int& operator[](std::size_t idx);
    void load(const std::string& filename);
    void save(const std::string& filename);
private:
    int real, imag;
};

#endif //PRAX03_COMPLEXNUMBER_H
