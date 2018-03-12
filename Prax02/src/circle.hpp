#ifndef PRAX02_CIRCLE_HPP
#define PRAX02_CIRCLE_HPP

#include "point.hpp"

/**
 * Create class Circle.
 * A circle is represented by a center point of type Point and radius of type float, let them be private.
 * Create a constructor taking a center Point and radius as arguments
 * Implement public methods:
 *     getCenter() -- method returns the center Point
 *     getRadius() -- method returns radius
 *     setRadius() -- methods takes a new radius as argument, returns nothing
 *     area() -- returns area of the circle as a single-precision floating-point value
 *     circumference() -- returns circumference of the circle as a single-precision floating-point value
 *     hasPoint(Point) -- returns True if the point lies on a circle, false otherwise.
 */

class Circle {
public:
    Circle(Point center, float radius);
    Point getCenter();
    float getRadius();
    void setRadius(float radius);
    float area();
    float circumference();
    bool hasPoint(const Point& p);
private:
    Point center;
    float radius;
};

#endif //PRAX02_CIRCLE_HPP
