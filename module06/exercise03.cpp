#include <iostream>
#include <algorithm> //for find()

using namespace std;

int arr[] = {11, 22, 33, 44, 55, 33, 66, 77, 33, 88};

int main() {
    int *ptr= arr;
    do {
        ptr = find(ptr, arr + 10, 33); //find first 33
        if (ptr == arr + 10){
            cout << "Cannot find 99 in the array" << endl;
            break;
        }
        else{
            cout << "First object with 33 found at offset " << (ptr - arr) << endl;
            ptr++;
        }
    } while (ptr != arr + 10);
    return 0;
}
