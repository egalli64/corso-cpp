/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Producer / consumer on an int
 *
 * g++ -pthread -Wall -o a.out e1_prod_cons_int.cpp
 */
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

namespace
{
std::mutex mtx;
std::condition_variable cnd;
constexpr int chunk = 2;

bool ready = false;
int stock = 10;

void consumer()
{
    while (stock > 0)
    {
        // acquire the mutex
        std::unique_lock lock{mtx};
        // release the mutex and wait until notified and the predicate is true or there is nothing to consume
        cnd.wait(lock, [] { return ready || stock <= 0; });

        // if there is anything to consume, work on it
        if (stock > 0)
        {
            stock -= chunk;
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
        // acquire the mutex
        std::unique_lock lock{mtx};

        std::cout << "Producer: " << ++stock << '\n';

        // notify to the consumers that a new production is done
        ready = true;
        cnd.notify_all();

        // release the mutex and wait until notified and the predicate is true
        cnd.wait(lock, [] { return !ready; });
    }

    // signal to the consumers that there is nothing more to consume
    cnd.notify_all();

    t1.join();
    t2.join();

    std::cout << "Done.\n";
}
