#include <iostream>
struct A {
   int x;
   explicit A(int value){ // #1
      this->x = value;
   }
   // disallow type conversion
   explicit A(int x1, int x2, int x3){} // #2
   A(std::initializer_list<int> values){}
};
int main() {
    A a1(42.3); // int -- conversion --> A
    A a2(42); // #1
    // A a3{42}; // #1
    A a4 = {42}; // #1
    A a5(1,2.0,3); // #2
    A a6{1,2,3}; // #2

    A a7= {1,2,3}; // #2: Error -> explicit
    A a8({1,2,3});
    return 0;
}
