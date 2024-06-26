/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * No need of std::ref(), std::cref() on lambda
 *
 * g++ -pthread -Wall -o a.out e4c_ref_lambda.cpp
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main()
{
    const std::vector<int> values{1, 2, 3, 4, 5, 6};
    int result;

    std::thread t{[&values, &result] { result = std::accumulate(values.cbegin(), values.cend(), 0); }};
    t.join();

    std::cout << "Sum is " << result << '\n';
}
