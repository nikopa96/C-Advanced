#include "gtest/gtest.h"
#include "../src/circle.hpp"

TEST (CircleTest, Initialization) {
    Circle c1(Point(0,0),10);
    Circle c2(Point(10,15),5);
    EXPECT_EQ(0,c1.getCenter().x);
    EXPECT_EQ(0,c1.getCenter().y);
    EXPECT_EQ(10,c2.getCenter().x);
    EXPECT_EQ(15,c2.getCenter().y);
    EXPECT_EQ(10,c1.getRadius());
    EXPECT_EQ(5,c2.getRadius());
    c1.setRadius(50.125); c2.setRadius(50.125);
    EXPECT_EQ(50.125,c1.getRadius());
    EXPECT_EQ(50.125, c2.getRadius());
};

TEST (CircleTest, Area) {
    Circle c1(Point(0,0),10);
    Circle c2(Point(10,15),5);
    EXPECT_NEAR(314.15,c1.area(),0.01);
    EXPECT_NEAR(62.83,c1.circumference(),0.01);
    EXPECT_NEAR(78.54,c2.area(),0.01);
    EXPECT_NEAR(31.42,c2.circumference(),0.01);
}