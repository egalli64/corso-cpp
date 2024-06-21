/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * (possible) deadlock when more resources are required
 *
 * g++ -pthread -Wall -o a.out e4_deadlock.cpp
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

double time_consuming_calculation()
{
    print("Spending some time do generate a double value");
    srand(time(nullptr));
    return cbrt(log(rand() % 100 + 1));
}
} // namespace

int main()
{
    double v1 = 1.1;
    std::mutex mtx_v1;
    double v2 = 2.2;
    std::mutex mtx_v2;

    print("!!! This code could lead to a deadlock !!!");

    std::thread t1{[&] {
        print("thread 1");

        std::lock_guard lock1{mtx_v1};
        print("thread 1, lock for v1");

        v1 = time_consuming_calculation();
        print("thread 1, set v1", v1, v2);

        std::lock_guard lock2{mtx_v2};
        print("thread 1, lock for v2");

        std::swap(v1, v2);
        print("thread 1 swap ->", v1, v2);
    }};

    std::thread t2{[&] {
        print("thread 2");

        std::lock_guard lock2{mtx_v2};
        print("thread 2, lock for v2");

        v2 = cbrt(42);
        print("thread 2, set v2", v1, v2);

        std::lock_guard lock1{mtx_v1};
        print("thread 2, lock for v1");

        std::swap(v1, v2);
        print("thread 2 swap ->", v1, v2);
    }};

    t1.join();
    t2.join();

    print("Done - when lucky");
}
