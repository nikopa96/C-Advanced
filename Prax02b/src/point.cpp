#include <cmath>
#include "point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(int cx, int cy) : x(cx), y(cy) {
}

bool Point::isOrigin() {
    return x == 0 and y == 0;
}

double Point::getX()const {
    return x;
}

double Point::getY()const {
    return y;
}

float Point::distanceTo(const Point &other) {
    return (float) sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
}