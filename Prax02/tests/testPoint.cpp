#include <cmath>
#include "gtest/gtest.h"
#include "../src/point.hpp"

TEST (PointTest, Initialization) {
    Point p0(0,0);
    Point p1(2,3);
    Point p2(5,10);
    EXPECT_EQ (0,p0.x);
    EXPECT_EQ (0,p0.y);
    EXPECT_EQ (2,p1.x);
    EXPECT_EQ (3,p1.y);
    EXPECT_EQ (5,p2.x);
    EXPECT_EQ (10,p2.y);
}

TEST (PointTest, IsOrigin) {
    Point p0(0,0);
    Point p1(2,3);
    EXPECT_TRUE(p0.isOrigin());
    EXPECT_FALSE(p1.isOrigin());
}

TEST (PointTest, DistanceBetweenTwoPoints) {
    Point p0(0,0);
    Point p1(2,3);
    Point p2(5,10);
    EXPECT_EQ(p0.distanceTo(p0), 0);
    EXPECT_NEAR(sqrt(13), p0.distanceTo(p1), 0.01);
    EXPECT_NEAR(p1.distanceTo(p2),p2.distanceTo(p1),0.01);
}
