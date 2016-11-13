#include <iostream>

using namespace std;

class Parent{
public:
    int a, b;
    virtual void foo(){cout << "parent" << endl;}
};

class Child : public Parent{
public:
    int c, d;
    virtual void foo(){cout << "child" << endl;}
};

int main(){
    Parent p;
    Child c;

    p.foo();
    c.foo();

    cout << "Parent Offset a = " << (size_t)&p.a - (size_t)&p << endl;
    cout << "Parent Offset b = " << (size_t)&p.b - (size_t)&p << endl;

    cout << "Child Offset a = " << (size_t)&c.a - (size_t)&c << endl;
    cout << "Child Offset b = " << (size_t)&c.b - (size_t)&c << endl;
    cout << "Child Offset c = " << (size_t)&c.c - (size_t)&c << endl;
    cout << "Child Offset d = " << (size_t)&c.d - (size_t)&c << endl;
}

