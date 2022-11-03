#include <iostream>

using namespace std;


int main(){
   int x[1024];
   int y = x[1024];
   cerr << "Line 9" << endl;
   int *p= new int[1024];
   p= p+52;
   delete []p;
   return 0;
}
