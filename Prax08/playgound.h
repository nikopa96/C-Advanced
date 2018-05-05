#ifndef PRAX08_PLAYGOUND_H
#define PRAX08_PLAYGOUND_H

class Base {
public:
    explicit Base(int x);
    ~Base();
};

class C1 : public virtual Base {
public:
    explicit C1(int x);
    ~C1();
};

class C2 : public virtual Base {
public:
    explicit C2(int x);
    ~C2();
};

class D : public C1, public C2 {
public:
    explicit D(int x);
    ~D();
};

class E : public D {
public:
    explicit E(int x);
    ~E();
};

#endif //PRAX08_PLAYGOUND_H
