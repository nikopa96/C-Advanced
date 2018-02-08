#include "line.hpp"

Line::Line(double slope, double offset) : a(slope), b(offset) {

}

Line::Line(Point pa, Point pb) : a(0), b(0) {

}

bool Line::hasPoint(const Point &p) {
    return false;
}

Point Line::intersect(const Line &other) {
    return Point();
}
