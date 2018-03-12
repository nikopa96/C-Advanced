#include "gtest/gtest.h"
#include "../src/line.hpp"

TEST (LineTest, Initialization) {
    Line l1(-2.0/3, 11.0/3);
    Line l2(Point(1,3), Point(-2,5));
    EXPECT_NEAR(-2.0/3, l1.a, 0.01);
    EXPECT_NEAR(-2.0/3, l2.a, 0.01);
    EXPECT_NEAR(11.0/3, l1.b, 0.01);
    EXPECT_NEAR(11.0/3, l2.b, 0.01);
}

TEST (LineTest, LinePoints) {
    Line l1(-2.0/3, 11.0/3);
    Line l2(Point(1,3), Point(-2,5));
    Point p1(1,3);
    Point p2(-2,5);
    Point p3(10,11);
    EXPECT_TRUE (l1.hasPoint(p1));
    EXPECT_TRUE (l1.hasPoint(p2));
    EXPECT_FALSE (l1.hasPoint(p3));
    EXPECT_TRUE (l2.hasPoint(p1));
    EXPECT_TRUE (l2.hasPoint(p2));
    EXPECT_FALSE (l2.hasPoint(p3));
}