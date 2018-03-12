#ifndef PRAX02_NUMBER_HPP
#define PRAX02_NUMBER_HPP

/**
 * Create class Number for performing elementary mathematical operations in the ring of integers
 * All methods implemented in this class should be static
 * Implement the following methods:
 *     add(a,b) -- returns the sum of two numbers
 *     difference(a,b) -- returns the difference of two numbers
 *     product(a,b) -- returns the product of two numbers
 *     quotient(a,b) -- returns the quotient of division of a by b
 *     remainder(a,b) -- returns the remainder of division of a by b
 *     gcd(a,b) -- returns the greatest common divisor of a and b. Hint: use Euclidean algorithm
 *     max(a,b) -- returns the biggest number
 *     min(a,b) -- returns the smallest number
 *     mean(a,b) -- returns a float-type mean value of a and b
 *     coPrime(a,b) -- returns True if a and b are co-prime, False otherwise.
 *                     Hint: numbers a and b are co-prime if gcd(a,b) is 1
 *     isEven(a) -- returns True if a is even, False otherwise
 *     isOdd(a) -- returns True if a is odd, False otherwise
 * Create nested class Series and implement the following methods in this class:
 *     factorial(a) -- returns a!
 *     fibonacci(a) -- returns Fib(a) value of the Fibonacci series
 *     harmonicSum(a) -- returns a double-precision floating point value representing harmonic number H(a)
 *
 */

class Number {
public:
    static int add(int a, int b);
    static int difference(int a, int b);
    static int product(int a, int b);
    static int quotient(int a, int b);
    static int remainder(int a, int b);
    static int gcd(int a, int b);
    static int max(int a, int b);
    static int min(int a, int b);
    static float mean(int a, int b);
    static bool coPrime(int a, int b);
    static bool isEven(int a);
    static bool isOdd(int a);
    class Series {
    public:
        static int factorial(int a);
        static int fibonacci(int a);
        static double harmonicSum(int a);
    };
};

#endif //PRAX02_NUMBER_HPP
