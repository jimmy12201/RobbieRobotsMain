#include <iostream>

using namespace std;

class Parent1{
public:
    int a1, b1;
    virtual void foo(){cout << "parent 1" << endl;}
};

class Parent2{
public:
    int a2, b2;
    virtual void foo(){cout << "parent 2" << endl;}
};


class Child : public Parent1, public Parent2 {
public:
    int c, d;
};

int main(){
    Parent1 p1;
    Parent2 p2;
    Child c;

    p1.foo();
    p2.foo();
    // c.foo();  // <-- Error: Ambiguous
    c.Parent1::foo();
    c.Parent2::foo();

    cout << "Parent1 Offset a1 = " << (size_t)&p1.a1 - (size_t)&p1 << endl;
    cout << "Parent1 Offset b1 = " << (size_t)&p1.b1 - (size_t)&p1 << endl;

    cout << "Parent2 Offset a2 = " << (size_t)&p2.a2 - (size_t)&p2 << endl;
    cout << "Parent2 Offset b2 = " << (size_t)&p2.b2 - (size_t)&p2 << endl;

    cout << "Child Offset a1 = " << (size_t)&c.a1 - (size_t)&c << endl;
    cout << "Child Offset b1 = " << (size_t)&c.b1 - (size_t)&c << endl;
    cout << "Child Offset a2 = " << (size_t)&c.a2 - (size_t)&c << endl;
    cout << "Child Offset b2 = " << (size_t)&c.b2 - (size_t)&c << endl;
    cout << "Child Offset c = " << (size_t)&c.c - (size_t)&c << endl;
    cout << "Child Offset d = " << (size_t)&c.d - (size_t)&c << endl;
}

