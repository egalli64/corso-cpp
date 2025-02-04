/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * unique_lock with defer_lock
 *
 * g++ -pthread -o a.out e1.cpp
 */
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

namespace
{
std::mutex mtx;
std::condition_variable cnd;

bool ready = false;
int stock = 10;

void consumer()
{
    while (stock > 0)
    {
        std::unique_lock<std::mutex> lock{mtx};
        cnd.wait(lock, [] { return ready; });

        stock -= 2;
        std::cout << "C:" << stock << ' ';
        ready = false;

        cnd.notify_one();
    }
}
} // namespace

int main()
{
    std::thread t{consumer};

    while (stock > 0)
    {
        std::unique_lock<std::mutex> lock{mtx};

        std::cout << "P:" << ++stock << ' ';
        ready = true;

        cnd.notify_one();
        cnd.wait(lock, [] { return !ready; });
    }

    t.join();
    std::cout << '\n';
}
