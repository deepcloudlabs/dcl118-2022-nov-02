#include <vector>
#include <iostream>
#include <numeric>

template<class T>
struct carp {
    T operator()(T u,T v){
        return u*v;
    }
};
int main(){
    std::vector<int> w{1,2,3,4,5,6,7,8,9};
    auto result = 1;
    auto sum = 0;
    for (const auto &n : w){
        result *= n;
        sum += n;
    }
    std::cout << "result: " << result << std::endl;
    std::cout << "sum: " << sum << std::endl;
    sum = std::accumulate(w.begin(),w.end(),int());
    std::cout << "accumulate sum: " << sum << std::endl;
    sum = std::accumulate(w.begin(),w.end(),0, [](int acc,int n){return acc+n;});
    std::cout << "accumulate sum: " << sum << std::endl;
    sum = std::accumulate(w.begin(),w.end(),int{0},std::plus<int>());
    std::cout << "accumulate sum: " << sum << std::endl;
    sum = std::accumulate(w.begin(),w.end(),int(0),std::plus<int>());
    std::cout << "accumulate sum: " << sum << std::endl;
    sum = std::accumulate(w.begin(),w.end(),int{1},std::multiplies<int>());
    std::cout << "accumulate factorial: " << sum << std::endl;

    sum = std::accumulate(w.begin(),w.end(),int{1},carp<int>());
    std::cout << "accumulate factorial: " << sum << std::endl;

    return 0;
}