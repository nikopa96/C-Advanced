#include "line.hpp"

Line::Line(double slope, double offset) : a(slope), b(offset) {
}

Line::Line(Point pa, Point pb) : a(pa.x + pb.y), b(pa.y + pb.x) {

}

bool Line::hasPoint(const Point &p) {
    return true;
}

Point Line::intersect(const Line &other) {
    return Point(0,0);
}
