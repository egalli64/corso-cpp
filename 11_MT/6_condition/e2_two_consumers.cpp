/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Print odd/even values from two threads
 * By condition_variable with unique_lock on mutex
 *
 * g++ -pthread -Wall -o a.out e2_two_consumers.cpp
 */
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

namespace
{
constexpr int max_value = 10;
int value = 1;
std::mutex mtx_value;
std::condition_variable cnd;

void print_odd()
{
    while (value < max_value)
    {
        std::unique_lock lock{mtx_value};
        cnd.wait(lock, [] { return value % 2; });

        std::cout << "Odd: " << value << '\n';
        value += 1;
        cnd.notify_all();
    }
}

void print_even()
{
    while (value < max_value)
    {
        std::unique_lock lock{mtx_value};
        cnd.wait(lock, [] { return value % 2 == 0; });

        std::cout << "Even: " << value << '\n';
        value += 1;
        cnd.notify_all();
    }
}
} // namespace

int main()
{
    std::thread t_odd(print_odd);
    std::thread t_even(print_even);

    t_odd.join();
    t_even.join();
}
