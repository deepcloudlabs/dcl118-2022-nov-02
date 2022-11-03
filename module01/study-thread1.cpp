#include <iostream>
#include <thread>

using namespace std;

static int result = 42;

void hello(int x,int y) {
    std::cout << "Hello Concurrent World!\n";
    result += x ;
    result *= y ;
}

struct task {
    int *task_data;

    explicit task(int taskData) {
        task_data = new int(taskData);
    }
    void operator()()  {
       std::cout << "Hello Concurrent World!\n";
       *(this->task_data) = 42;
    }
};

task my_task{10};
std::thread t2(my_task); // 2. struct/class operator()

int main() {
    std::thread t1(hello,10,20); // 1. c function
    thread t3([](){ // 3. lambda expression
       std::cout << "Hello Concurrent World!\n";
    });
    auto t_id = t3.native_handle();
    cout << t_id << endl;
    t1.join();
    t2.join();
    t3.join();
    cout << result << endl;
    cout << *(my_task.task_data) << endl;
}
