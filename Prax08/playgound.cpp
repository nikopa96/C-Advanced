#include "playgound.h"
#include <iostream>

Base::Base(int x) {
    std::cout << "Base::Base(int)" << std::endl;
}

Base::~Base() {
    std::cout << "Base::~Base()" << std::endl;
}

C1::C1(int x) : Base(x) {
    std::cout << "C1::C1()" << std::endl;
}

C1::~C1() {
    std::cout << "C1::~C1()" << std::endl;
}

C2::C2(int x) : Base(x) {
    std::cout << "C2::C2()" << std::endl;
}

C2::~C2() {
    std::cout << "C2::~C2()" << std::endl;
}

D::D(int x) : C1(x), C2(x), Base(x) {
    std::cout << "D::D()" << std::endl;
}

D::~D() {
    std::cout << "D::D()" << std::endl;
}

E::E(int x) : D(x), Base(x) {
    std::cout << "E::E()" << std::endl;
}

E::~E() {
    std::cout << "E::~E()" << std::endl;
}
