/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lock guard on int
 *
 * g++ -pthread -o a.out e2_guard_int.cpp
 */
#include <iostream>
#include <mutex>
#include <thread>

int main()
{
    int result = 0;
    std::mutex mtx_result;
    const int count = 50'000;

    std::thread t{[&result, &mtx_result] {
        for (int i = 0; i < count; ++i)
        {
            std::lock_guard<std::mutex> lock{mtx_result};
            result++;
        }
    }};

    for (int i = 0; i < count; ++i)
    {
        std::lock_guard<std::mutex> lock{mtx_result};
        result++;
    }

    t.join();
    std::cout << "Guarded behavior: " << result << '\n';
}
