#include <iostream>

using namespace std;

struct A {
    byte u; // 1
    // 7
    double y; // 8
    byte v; // 1
    // 3
    int x; // 4
};

struct B {
    int *p; // 8
    int x;  // 4
    // 4
    virtual void fun(){}
    void gun(){}
    void sun(){}
    void run(){}
};

int main(){
    cout << sizeof(B) << endl;
    B b; // virtual table address
    // fun(&b) -> Text
    b.fun();  // static-binding
    B *p = &b;
    p->fun(); // VT -> dynamic-binding
    return 0;
}
