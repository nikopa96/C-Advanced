#include "point.hpp"

Point::Point() : x(0), y(0) {

}

Point::Point(int cx, int cy) : x(cx), y(cy) {

}

bool Point::isOrigin() {
    return false;
}

float Point::distanceTo(const Point &other) {
    return 0;
}