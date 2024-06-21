/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lock guard on an int
 *
 * g++ -pthread -Wall -o a.out e2_guard_int.cpp
 */
#include <iostream>
#include <mutex>
#include <thread>

int main()
{
    constexpr int count = 50'000;
    int result = 0;
    std::mutex mtx_result;

    std::thread t{[&result, &mtx_result] {
        for (int i = 0; i < count; ++i)
        {
            std::lock_guard lock{mtx_result};
            ++result;
        }
    }};

    for (int i = 0; i < count; ++i)
    {
        std::lock_guard lock{mtx_result};
        ++result;
    }

    t.join();
    std::cout << "Guarded behavior when racing on result: " << result << '\n';
}
