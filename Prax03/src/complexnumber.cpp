#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "complexnumber.h"

namespace pt = boost::property_tree;

ComplexNumber::ComplexNumber(int real, int imag) {
    this->real = real;
    this->imag = imag;
    std::cout << "Constructing " << *this << std::endl;
}

// copy-constructor
ComplexNumber::ComplexNumber(const ComplexNumber &c) {
    this->real = c.real;
    this->imag = c.imag;
    std::cout << "Copy-constructing from " << c << std::endl;
}

// move-constructor
ComplexNumber::ComplexNumber(ComplexNumber &&c) noexcept {
    std::cout << "Move-constructing from " << c << std::endl;
    this->real = c.real;   c.real = 0;
    this->imag = c.imag;   c.imag = 0;
}

// copy-assignment operator
ComplexNumber &ComplexNumber::operator=(const ComplexNumber &c) {
    this->real = c.real;
    this->imag = c.imag;
    std::cout << "Copy-assigning from " << c << std::endl;
    return *this;
}

// move-assignment operator
ComplexNumber &ComplexNumber::operator=(ComplexNumber &&c) noexcept {
    std::cout << "Move-assigning from " << c << std::endl;
    this->real = c.real;   c.real = 0;
    this->imag = c.imag;   c.imag = 0;
    return *this;
}

// output stream insertion operator
std::ostream &operator<<(std::ostream &os, const ComplexNumber &c) {
    os << "(" << c.real << "," << c.imag << "i)";
    return os;
}

// input stream extraction operator
std::istream &operator>>(std::istream &is, ComplexNumber &c) {
    is >> c.real >> c.imag;
    return is;
}

// infix increment operator
ComplexNumber &ComplexNumber::operator++() {
    this->real += 1;
    return *this;
}

// postfix increment operator
ComplexNumber ComplexNumber::operator++(int i) {
    ComplexNumber tmp(*this);
    operator++();
    return tmp;
}

bool ComplexNumber::operator==(const ComplexNumber &c) {
    return this->real == c.real && this->imag == c.imag;
}

bool operator<(const ComplexNumber &a, const ComplexNumber &b) {
    return a.real < b.real || ( a.real == b.real && a.imag < b.imag );
}

ComplexNumber operator+(ComplexNumber a, const ComplexNumber &b) {
    a.real += b.real;
    a.imag += b.imag;
    return a;
}

ComplexNumber operator-(ComplexNumber a, const ComplexNumber &b) {
    a.real -= b.real;
    a.imag -= b.imag;
    return a;
}

ComplexNumber operator*(ComplexNumber a, const ComplexNumber &b) {
    int real = a.real * b.real - a.imag * b.imag;
    int imag = a.real * b.imag + a.imag * b.real;
    return a;
}

int &ComplexNumber::operator[](std::size_t idx) {
    if ( idx == 0 ) return this->real;
    else return this->imag;
}

void ComplexNumber::load(const std::string &filename) {
    pt::ptree tree;
    pt::read_xml(filename, tree);
    this->real = tree.get<int>("complexNumber.realPart");
    this->imag = tree.get<int>("complexNumber.imagPart");
}

void ComplexNumber::save(const std::string &filename) {
    pt::ptree tree;
    tree.put("complexNumber.realPart", this->real);
    tree.put("complexNumber.imagPart", this->imag);
    pt::write_xml(filename, tree);
}

