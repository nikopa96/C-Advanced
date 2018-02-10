#include "gtest/gtest.h"
#include "../src/number.hpp"

TEST (NumberTest, Addition) {
    EXPECT_EQ (2, Number::add(1,1));
    EXPECT_EQ (0, Number::add(5,-5));
    EXPECT_EQ (-15, Number::add(-5, -10));
}

TEST (NumberTest, Difference) {
    EXPECT_EQ (0, Number::difference(1,1));
    EXPECT_EQ (10, Number::difference(5,-5));
    EXPECT_EQ (5, Number::difference(-5,-10));
}

TEST (NumberTest, Product) {
    EXPECT_EQ (1, Number::product(1,1));
    EXPECT_EQ (-25, Number::product(5,-5));
    EXPECT_EQ (50, Number::product(-5,-10));
}

TEST (NumberTest, Quotient) {
    EXPECT_EQ (1, Number::quotient(1,1));
    EXPECT_EQ (2, Number::quotient(5,2));
    EXPECT_EQ (2, Number::quotient(7,3));
    EXPECT_EQ (3, Number::quotient(7,2));
}

TEST (NumberTest, Remainder) {
    EXPECT_EQ (0, Number::remainder(1,1));
    EXPECT_EQ (1, Number::remainder(5,2));
    EXPECT_EQ (1, Number::remainder(7,3));
    EXPECT_EQ (1, Number::remainder(7,2));
}

TEST (NumberTest, GCD) {
    EXPECT_EQ (5, Number::gcd(100,35));
    EXPECT_EQ (1, Number::gcd(100,59));
    EXPECT_EQ (3, Number::gcd(12,9));
    EXPECT_EQ (1, Number::gcd(27,4));
}

TEST (NumberTest, CoPrime) {
    EXPECT_EQ (false, Number::coPrime(100,35));
    EXPECT_EQ (true, Number::coPrime(100,59));
    EXPECT_EQ (false, Number::coPrime(12,9));
    EXPECT_EQ (true, Number::coPrime(27,4));
}

TEST (NumberTest, IsEven) {
    EXPECT_EQ (true, Number::isEven(2));
    EXPECT_EQ (true, Number::isEven(12));
    EXPECT_EQ (false, Number::isEven(7));
    EXPECT_EQ (false, Number::isEven(11));
}

TEST (NumberTest, IsOdd) {
    EXPECT_EQ (false, Number::isOdd(2));
    EXPECT_EQ (false, Number::isOdd(12));
    EXPECT_EQ (true, Number::isOdd(7));
    EXPECT_EQ (true, Number::isOdd(11));
}

TEST (NumberTest, Max) {
    EXPECT_EQ (2, Number::max(2,2));
    EXPECT_EQ (5, Number::max(3,5));
}

TEST (NumberTest, Min) {
    EXPECT_EQ (2, Number::min(2,2));
    EXPECT_EQ (3, Number::min(3,5));
}

TEST (NumberTest, MeanValue) {
    EXPECT_NEAR(2.0, Number::mean(2,2), 0);
    EXPECT_NEAR(4.0, Number::mean(3,5), 0.01);
    EXPECT_NEAR(3.5, Number::mean(4,3), 0.01);
}

TEST (NumberTest, Factorial) {
    EXPECT_EQ (1, Number::Series::factorial(0));
    EXPECT_EQ (1, Number::Series::factorial(1));
    EXPECT_EQ (6, Number::Series::factorial(3));
    EXPECT_EQ (120, Number::Series::factorial(5));
    EXPECT_EQ (5040, Number::Series::factorial(7));
    EXPECT_EQ (3628800, Number::Series::factorial(10));
}

TEST (NumberTest, Fibonacci) {
    EXPECT_EQ (0, Number::Series::fibonacci(0));
    EXPECT_EQ (1, Number::Series::fibonacci(1));
    EXPECT_EQ (5, Number::Series::fibonacci(5));
    EXPECT_EQ (55, Number::Series::fibonacci(10));
    EXPECT_EQ (610, Number::Series::fibonacci(15));
    EXPECT_EQ (6765, Number::Series::fibonacci(20));
    EXPECT_EQ (75025, Number::Series::fibonacci(25));
}

TEST (NumberTest, Harmonic) {

    EXPECT_NEAR(11.0/6, Number::Series::harmonicSum(3), 0.01);

}