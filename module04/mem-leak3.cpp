#include <iostream>

using namespace std;


int main(){
    int x ;
    int *p= new int[10];
    p[10]=42;
    cout << "x= " << x << endl;
    delete []p;
    return 0;
}
