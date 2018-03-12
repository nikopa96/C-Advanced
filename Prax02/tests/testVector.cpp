#include "gtest/gtest.h"
#include "../src/vector.hpp"

TEST (VectorTest, Initialization) {
    Vector v1(3,7);
    Vector v2(2,5);
    EXPECT_EQ(3,v1.getX());
    EXPECT_EQ(7,v1.getY());
    EXPECT_EQ(2,v2.getX());
    EXPECT_EQ(5,v2.getY());
};

TEST (VectorTest, Length) {
    Vector v1(3,7);
    Vector v2(2,5);
    EXPECT_NEAR(7.62,v1.length(),0.01);
    EXPECT_NEAR(5.38,v2.length(),0.01);
};

TEST (VectorTest, Negate) {
    Vector v1(3,7);
    v1.negate();
    EXPECT_NEAR(-3,v1.getX(),0.01);
    EXPECT_NEAR(-7,v1.getY(),0.01);
};

TEST (VectorTest, ScalarProduct) {
    Vector v1(3,7);
    v1.scalarProduct(10);
    EXPECT_NEAR(30,v1.getX(),0.01);
    EXPECT_NEAR(70,v1.getY(),0.01);
};

TEST (VectorTest, VectorSum) {
    Vector v1(3,7);
    Vector v2(2,5);
    v2.vectorSum(v1);
    EXPECT_NEAR(5,v2.getX(),0.01);
    EXPECT_NEAR(12,v2.getY(),0.01);
};

TEST (VectorTest, NormalizeVector) {
    Vector v1(3,7);  v1.normalize();
    Vector v2(2,5);  v2.normalize();
    EXPECT_NEAR(1,v1.length(),0.01);
    EXPECT_NEAR(1,v2.length(),0.01);
};