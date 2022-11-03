#include <iostream>
#include <thread>
#include <future>
using namespace std;

long sequence(long n) { // 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
    auto step = 0L;
    while (n > 1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        step++;
    }
    return step;
}

int main(){
    future<long> my_future = async(sequence, 17);
    // working hard...
    long result = my_future.get();
    cout << result << endl;
}