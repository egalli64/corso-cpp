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
    std::mutex mtx;
    int result{0};
    constexpr int count{50'000};

    std::thread t{[&] {
        for (int i = 0; i < count; ++i)
        {
            mtx.lock();
            result++;
            mtx.unlock();
        }
    }};

    for (int i = 0; i < count; ++i)
    {
        mtx.lock();
        result++;
        mtx.unlock();
    }

    t.join();
    std::cout << "No data race: " << result << '\n';
}
