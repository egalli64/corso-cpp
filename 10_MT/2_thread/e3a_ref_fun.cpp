/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::ref(), std::cref() on function
 *
 * g++ -pthread -o a.out e3a_ref_fun.cpp
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

namespace
{
void adder_function(const std::vector<int> &values, int &result)
{
    result = std::accumulate(values.begin(), values.end(), 0);
}
} // namespace

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6};
    int result;

    std::thread t{adder_function, std::cref(values), std::ref(result)};
    // forgetting to explicitly remark the references leads to compilation errors 
    // std::thread t{adder_function, values, result}; // won't compile
    t.join();

    std::cout << "Sum is " << result << '\n';
}
