/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lock guard on vector
 *
 * g++ -pthread -o a.out e3_guard_vector.cpp
 */
#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace
{
std::vector<int> data;
std::mutex mtx_data;

void add(int value)
{
    std::lock_guard<std::mutex> lock{mtx_data};
    data.push_back(value);
}

bool contains(int value)
{
    std::lock_guard<std::mutex> lock{mtx_data};
    return std::find(data.begin(), data.end(), value) != data.end();
}
} // namespace

int main()
{
    if (contains(42))
    {
        std::cout << "Unexpected\n";
    }

    std::thread t{[] { add(42); }};

    if (contains(42))
    {
        std::cout << "Could be, could be not\n";
    }

    t.join();
    if (!contains(42))
    {
        std::cout << "Unexpected\n";
    }

    std::cout << "Done\n";
}
