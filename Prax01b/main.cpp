#include <iostream>

using namespace std;

int main() {

    //declaration
    int a;
    int b, c;

    //assignment
    a = 5;

    //initialization = declaration + assignment
    int d = 5;  //C++98
    int e(5); //Constructor initialization C++11
    int f(5); //uniform initialization C++11

    //values are normally converted for unsigned representation
    unsigned int u = 10; int i = 42;
    cout << i+i << endl;
    cout << u+i << endl;

    unsigned u1 = 42; int u2 = 10;
    cout << u1 - u2 << endl;
    cout << u2 - u1 << endl;

    //Type aliases
    //C++ C-like syntax
    //typedef [type], [alias]

    typedef char byte;
    typedef short word;
    typedef int dword;
    typedef long qword;

    //C++11 syntax
    //Using [alias] = [type]
    using byte = char;
    using word = short;
    using dword = int;
    using qword = long;

    //usage example
    using salary = int;
    using budget = int;
    salary managerSalary = 1000;
    budget projectBudget = 120000;

    //specifier that returns the type of its operand - decltype
    int q = 5;
    decltype(q) w = 10; //variable w is of whatever type q is

    //f() -> string
    //decltype(f()) t;

    //C++98 const
    const int o = 5;
    //o = 6;

    //C++11 constexpr
    constexpr int l = 5;
    constexpr int l1 = 1, l2 = 5, l3 = 6;

    //number to boolean conversion
    //1 is logical true
    //0 is logical false

    int _a = -5, _b = 10;
    while (_a) {
        _a++;
    }

    int a1 = 5;
    bool b2= a;
    int c3 = b;

    //static_cast
    //signed char k = -200; out of range

    //automatic variable
    //auto z = 5; incorrect

    auto z = 5;
    auto s = 1.5;
    auto z2 = 1.5f;
    auto z3 = "Hi";
    auto r4 = 1.5L;
    auto r5 = 5u;
    auto r6 = 51;
    auto r8 = 0x2ALL;

    double d1 = 9/6; //1.0
    double d2 = 9.0 / 6; //1.5

    cout << "Hello, World!" << endl;
    string s = string("Foo");
    return 0;
}