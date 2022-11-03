#include <iostream>

using namespace std;


int main(){
   int *p= new int[1024];
   int *q= p;
   for (int i=0;i<100000;++i,++q)
   {  
       cerr << hex << q << ": " << dec << i << endl;
       *q= i;
   }
   return 0;
}
