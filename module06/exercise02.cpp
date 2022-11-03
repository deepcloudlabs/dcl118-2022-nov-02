#include <list>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    deque<int> numbers{4, 8, 15, 16, 23, 42};
    numbers.resize(4,1);
    cout << "max_size: " << numbers.max_size() << endl;
    cout << "size: " << numbers.size() << endl;
    numbers.insert(numbers.begin(),56);
    numbers.insert(numbers.begin(),63);
    cout << "max_size: " << numbers.max_size() << endl;
    cout << "size: " << numbers.size() << endl;
    for (auto &number : numbers)
        cout << number << ", ";
    auto p=numbers.begin();
    while (p != numbers.end()){
        auto number = *p;
        cout << number << ", ";
        p++;
    }
}