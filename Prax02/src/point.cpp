#include "point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(double cx, double cy) : x(cx), y(cy)  {
}

bool Point::isOrigin() {
    return true;
}

double Point::distanceTo(const Point &p) {
    return 0;
}

