/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 *
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
        if (stock > 0)
        {
            stock -= 2;
            std::cout << "Consumer " << std::this_thread::get_id() << ": " << stock << '\n';
            ready = false;

            cnd.notify_all();
        }
        else
        {
            std::cout << "Consumer " << std::this_thread::get_id() << ": too late!\n";
        }
    }
}
} // namespace

int main()
{
    std::thread t1{consumer};
    std::thread t2{consumer};

    while (stock > 0)
    {
        std::unique_lock<std::mutex> lock{mtx};

        std::cout << "Producer: " << ++stock << '\n';
        ready = true;

        cnd.notify_all();
        cnd.wait(lock, [] { return !ready; });
    }

    ready = true;
    cnd.notify_all();
    t1.join();
    t2.join();
    std::cout << "Done.\n";
}
