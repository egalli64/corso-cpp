/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * No need of std::ref(), std::cref() on lambda
 *
 * g++ -pthread -o a.out e3c_ref_lambda.cpp
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6};
    int result;

    std::thread t{[&values, &result] { result = std::accumulate(values.begin(), values.end(), 0); }};
    t.join();

    std::cout << "Sum is " << result << '\n';
}
