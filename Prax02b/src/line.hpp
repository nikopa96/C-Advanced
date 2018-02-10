#ifndef PRAX02_LINE_HPP
#define PRAX02_LINE_HPP

#include "point.hpp"

/**
 * Create a class Line represented by an equation y = ax + b
 * Let a and b be double-precision floating-point numbers, let them be const and public.
 * Create a constructor Line(a,b) where the user can pass values for a and b explicitly.
 * Create a constructor Line(Point a, Point b) which constructs the line by the specified two points that it intersects.
 * Implement the following methods:
 *     hasPoint(Point) -- returns True if the specified point lies on the line
 *     intersect(Line) -- returns an object of type Point, which is an intersection point of this line and the line
 *                        specified as argument to the method.
 *
 */

class Line {
public:
    Line(double slope, double offset);
    Line(Point pa, Point pb);
    bool hasPoint(const Point& p);
    Point intersect(const Line& other);
    double a, b;
};

#endif //PRAX02_LINE_HPP
