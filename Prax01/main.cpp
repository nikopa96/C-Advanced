#include <iostream>

using namespace std;

int main() {

    // declaration
    int a;   // signed integer
    int b,c; // signed integers

    // assignment
    a = 5;

    // initialization = declaraion + assignment
    int d = 5;      // C++98
    int e(5);       // constructor style initialization, C++11
    int f{5};       // uniform initialization, C++11

    //values are normally converted to unsigned representation
    unsigned int u = 10; int i = 42;
    cout << i+i << endl;
    cout << u+i << endl;

    unsigned u1 = 42, u2 = 10;
    cout << u1 - u2 << endl;
    cout << u2 - u1 << endl;

    // Type Aliases
    // C++98 C-like syntax
    // typedef [type] [alias]
    typedef char byte;
    typedef short word;
    typedef int dword;
    typedef long qword;

    // C++11 syntax
    // using [alias] = [type]
    using byte = char;
    using word = short;
    using dword = int;
    using qword = long;

    // usage example
    using salary = int;
    using budget = int;
    salary managerSalary = 1000;
    budget projectBudget = 125000;

    // specifier that returns the type of its operand - decltype
    int q = 5;
    decltype(q) w = 10;  // variable w is of whatever type q is
    //decltype(f()) t;   // variable t of type equal to the type returned by f()

    // C++98 const
    const int o = 5;

    // C++11
    // constexpr
    constexpr int l = 5;
    constexpr int l1 = 1,l2 = 2,l3 = 3;

    // number to boolean conversion
    // anything that is not zero is True
    // zero - logical False

    // type conversion
    // static_cast<T>(p)
    long double pi(3.14149);
    double piD = static_cast<double>(pi);
    float piF = static_cast<float>(pi);
    int piI = static_cast<int>(pi);

    // WARNING! out-of-range value for signed variable is UB!
    //signed char k = -200;

    // Auto variables
    // auto z;    automatic variables must be initialized
    auto z = 5;      // z is integer
    auto z1 = 1.5;   // z is double
    auto z2 = 1.5f;  // z is float
    auto z3 = "Hi"s; // z is string, C++14
    auto z4 = 1.5L;  // z is long double
    auto z5 = 5u;    // z is unsigned int
    auto z6 = 5l;    // z is signed long int
    auto z7 = 0x2ALL; // z is signed long long int
    auto z8 = 0b101010ull; // z is unsigned long long int

    double d1 = 9/6;  // 1.0
    double d2 = 9.0 / 6; // 1.5

    cout << "Hello, World!" << endl;
    string s = string("Foo");

    return 0;
}
