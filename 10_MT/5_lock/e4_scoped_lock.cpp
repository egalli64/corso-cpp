/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * No deadlock using scoped_lock
 *
 * g++ -pthread -Wall -o a.out e4_scoped_lock.cpp
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
    std::scoped_lock lock{mtx_cout};
    std::cout << std::this_thread::get_id() << ' ' << message << '\n';
}

void print(const char *message, double a, double b)
{
    std::scoped_lock lock{mtx_cout};
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
            std::scoped_lock lock{mtx_v1};
            print("thread 1 scoped lock on v1");
            v1 = cbrt(log(rand() % 100 + 1));
        }
        print("thread 1, set v1", v1, v2);

        std::scoped_lock lock{mtx_v1, mtx_v2};
        print("thread 1 scoped lock on _both_ v1 and v2");

        std::swap(v1, v2);
        print("thread 1 swap ->", v1, v2);
    }};

    std::thread t2{[&] {
        print("thread 2");

        {
            std::scoped_lock lock{mtx_v2};
            print("thread 2 scoped lock on v1");
            v2 = cbrt(42);
        }
        print("thread 2, set v2", v1, v2);

        std::scoped_lock lock{mtx_v1, mtx_v2};
        print("thread 2 scoped lock on _both_ v1 and v2");

        std::swap(v1, v2);
        print("thread 2 swap ->", v1, v2);
    }};

    t1.join();
    t2.join();

    std::cout << "Done\n";
}
