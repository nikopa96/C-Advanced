#include "number.hpp"

int Number::add(int a, int b) {
    return a + b;
}

int Number::difference(int a, int b) {
    return a - b;
}

int Number::product(int a, int b) {
    return a * b;
}

int Number::quotient(int a, int b) {
    return a / b;
}

int Number::remainder(int a, int b) {
    return a % b;
}

int Number::gcd(int a, int b) {
    while (a != 0 and b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    return a + b;
}

int Number::max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int Number::min(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

float Number::mean(int a, int b) {
    return (float) (a + b) / 2;
}

bool Number::coPrime(int a, int b) {
    while (a != 0 and b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    return a + b == 1 || a + b == -1;
}

bool Number::isEven(int a) {
    return a % 2 == 0;
}

bool Number::isOdd(int a) {
    return a % 2 != 0;
}

int Number::Series::factorial(int a) {
    if (a == 0) {
        return 1; //Test was wrong: 0! must be 1. In tests 0! was 0
    } else {
        int n = 1;

        for (int i = 1; i <= a; i++) {
            n = n * i;
        }

        return n;
    }
}

int Number::Series::fibonacci(int a) {
    int fib1 = 0;
    int fib2 = 1;
    int fibo = 1;

    if (a == 0) {
        return 0;
    } else {
        for (int i = 1; i < a; i++) {
            fibo = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibo;
        }
    }

    return fibo;
}

float Number::Series::harmonicSum(int a) {
    float sum = 0;

    for (int i = 1; i <= a; i++) {
        sum += (float) 1/i;
    }
    return sum;
}
