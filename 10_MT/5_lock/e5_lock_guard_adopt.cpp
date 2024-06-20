/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * No deadlock using lock() plus lock_guard with adopt_lock
 *
 * g++ -pthread -Wall -o a.out e5_lock_guard_adopt.cpp
 */
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

namespace
{
std::mutex mtx_cout;

void print(const char *message)
{
    std::lock_guard lock{mtx_cout};
    std::cout << std::this_thread::get_id() << ' ' << message << '\n';
}

void print(const char *message, double a, double b)
{
    std::lock_guard lock{mtx_cout};
    std::cout << std::this_thread::get_id() << ' ' << message << ' ' << a << ", " << b << '\n';
}
} // namespace

int main()
{
    double v1 = 1.1;
    std::mutex mtx_v1;
    double v2 = 2.2;
    std::mutex mtx_v2;

    std::thread t1{[&] {
        print("thread 1");

        print("Spending some time do generate a double value");
        srand(time(nullptr));
        {
            std::lock_guard lock1{mtx_v1};
            print("thread 1 lock guard on v1");
            v1 = cbrt(log(rand() % 100 + 1));
        }
        print("thread 1, set v1", v1, v2);

        std::lock(mtx_v1, mtx_v2);
        std::lock_guard lock1{mtx_v1, std::adopt_lock};
        std::lock_guard lock2{mtx_v2, std::adopt_lock};
        print("thread 1 lock guard on _both_ v1 and v2");

        std::swap(v1, v2);
        print("thread 1 swap ->", v1, v2);
    }};

    std::thread t2{[&] {
        print("thread 2");

        {
            std::lock_guard lock1{mtx_v2};
            print("thread 2 lock guard on v1");
            v2 = cbrt(42);
        }
        print("thread 2, set v2", v1, v2);

        std::lock(mtx_v1, mtx_v2);
        std::lock_guard lock2{mtx_v2, std::adopt_lock};
        std::lock_guard lock1{mtx_v1, std::adopt_lock};
        print("thread 2 lock guard on _both_ v1 and v2");

        std::swap(v1, v2);
        print("thread 2 swap ->", v1, v2);
    }};

    t1.join();
    t2.join();

    std::cout << "Done\n";
}
