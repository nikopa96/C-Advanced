#include "vector.hpp"
#include <cmath>

Vector::Vector(float dX, float dY) : x(dX), y(dY){
}

float Vector::getX()const {
    return x;
}

float Vector::getY()const {
    return y;
}

float Vector::length() {
    return (float) sqrt(pow(x, 2) + pow(y, 2));
}

void Vector::negate() {
    x = -x;
    y = -y;
}

void Vector::scalarProduct(int a) {
    x = a * x;
    y = a * y;
}

void Vector::vectorSum(const Vector &other) {
    x += other.getX();
    y += other.getY();
}

void Vector::normalize() {
    auto module = (float) sqrt(pow(x, 2) + pow(y, 2));

    x = x / module;
    y = y / module;
}