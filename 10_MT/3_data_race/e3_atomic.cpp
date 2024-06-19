/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Synchronization by atomic variable
 *
 * g++ -pthread -Wall -o a.out e3_atomic.cpp
 */
#include <atomic>
#include <iostream>
#include <thread>

int main()
{
    constexpr int count = 50'000;
    std::atomic<int> result = 0;

    std::thread t{[&result] {
        for (int i = 0; i < count; ++i)
        {
            ++result;
        }
    }};

    for (int i = 0; i < count; ++i)
    {
        ++result;
    }

    t.join();
    std::cout << "No data race: " << result << '\n';
}
