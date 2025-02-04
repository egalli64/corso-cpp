/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * unique_lock with defer_lock
 *
 * g++ -pthread -o a.out e5_lock_unique_defer.cpp
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
    std::lock_guard<std::mutex> lock{mtx_cout};
    std::cout << std::this_thread::get_id() << ' ' << message << '\n';
}

void print(const char *message, double a, double b)
{
    std::lock_guard<std::mutex> lock{mtx_cout};
    std::cout << std::this_thread::get_id() << ' ' << message << ' ' << a << ", " << b << '\n';
}
} // namespace

int main()
{
    double v1{12.23};
    double v2{32.21};
    std::mutex mtx_v1;
    std::mutex mtx_v2;

    std::thread t1{[&] {
        print("thread 1");

        srand(time(nullptr));
        v1 = cbrt(log(rand() % 100 + 1));
        print("set v1", v1, v2);

        std::unique_lock<std::mutex> lock1{mtx_v1, std::defer_lock};
        std::unique_lock<std::mutex> lock2{mtx_v2, std::defer_lock};
        std::lock(lock1, lock2);
        print("thread 1 locked");

        std::swap(v1, v2);
        print("swap 1 ->", v1, v2);
    }};

    std::thread t2{[&] {
        print("thread 2");

        v2 = cbrt(42);
        print("set v2", v1, v2);

        std::unique_lock<std::mutex> lock1{mtx_v1, std::defer_lock};
        std::unique_lock<std::mutex> lock2{mtx_v2, std::defer_lock};
        std::lock(lock1, lock2);
        print("thread 2 locked");

        std::swap(v1, v2);
        print("swap 2 ->", v1, v2);
    }};

    t1.join();
    t2.join();

    std::cout << "Done\n";
}
