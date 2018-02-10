#include "circle.hpp"
#include <cmath>

Circle::Circle(Point c, float newRadius) : center(c), radius(newRadius) {
}

Point Circle::getCenter() {
    return center;
}

float Circle::getRadius() {
    return radius;
}

void Circle::setRadius(float newRadius) {
    radius = newRadius;
}

float Circle::area() {
    return (float) (M_PI * pow(radius, 2));
}

float Circle::circumference() {
    return (float) (2 * M_PI * radius);
}

bool Circle::hasPoint(const Point &p) {
    return (float) pow(p.getX(), 2) + pow(p.getY(), 2) == (float) pow(radius, 2);
}

