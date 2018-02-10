#include "line.hpp"

Line::Line(double slope, double offset) : a(slope), b(offset) {
}

Line::Line(Point pa, Point pb) {
    auto slope = (float) ((pa.getY() - pb.getY()) / (pa.getX() - pb.getX()));
    auto offset = pb.getY() - slope * pb.getX();

    a = slope;
    b = offset;
}

bool Line::hasPoint(const Point &p) {
    return (float) p.getY() == (float) (a * p.getX() + b);
}

Point Line::intersect(const Line &other) {
    return Point();
}
