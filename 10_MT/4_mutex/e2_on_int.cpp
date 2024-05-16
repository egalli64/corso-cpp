/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Mutex to synchronize int access
 *
 * g++ -pthread -o a.out e2_on_int.cpp
 */
#include <iostream>
#include <mutex>
#include <thread>

int main()
{
    const int count = 50'000;
    std::mutex mtx_result;
    int result = 0;

    std::thread t{[&mtx_result, &result] {
        for (int i = 0; i < count; ++i)
        {
            mtx_result.lock();
            result++;
            mtx_result.unlock();
        }
    }};

    for (int i = 0; i < count; ++i)
    {
        mtx_result.lock();
        result++;
        mtx_result.unlock();
    }

    t.join();
    std::cout << "No data race: " << result << '\n';
}
