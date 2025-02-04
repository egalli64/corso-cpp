/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lock guard on cout
 *
 * g++ -pthread -o a.out e1_guard_cout.cpp
 */
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

int main()
{
    std::cout << "Cout access protected by mutex\n";
    std::mutex mtx_cout;

    auto greeter = [&mtx_cout](const std::string &s) {
        std::lock_guard<std::mutex> lock{mtx_cout};
        for (int i = 0; i < 1'000; i++)
        {
            std::cout << s[0];
        }

        std::cout << s;
        std::cout << " from ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
    };

    std::thread t1{greeter, "Hello"};
    std::thread t2{greeter, "Goodbye"};

    { // ensure the lock is freed as soon as possible - beware of deadlock!
        std::lock_guard<std::mutex> lock{mtx_cout};
        std::cout << "The main thread is ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
    }

    t1.join();
    t2.join();
}
