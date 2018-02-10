#ifndef PRAX02_POINT_HPP
#define PRAX02_POINT_HPP

/**
 * Create class Point representing a 2-dimensional point.
 * Let it have coordinates named x and y, which are read-only (public and constant) double-precision floaring-point values.
 * Create a constructor which allows to set the coordinates explicitly
 * Implement the following methods:
 *     isOrigin() -- returns True if the point is at origin (0,0)
 *     distanceTo(Point) -- returns the distance to another point.
 *                          Hint: use Euclidean distance in 2-dimensional space.
 */

class Point {
public:
    Point();
    Point(int x, int y);
    const double x, y;
    bool isOrigin();
    float distanceTo(const Point& other);
    double getX()const;
    double getY()const;
};

#endif //PRAX02_POINT_HPP
