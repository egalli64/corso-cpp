/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Mutex to synchronize cout access
 *
 * g++ -pthread -o a.out e1_on_cout.cpp
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
        mtx_cout.lock();
        for (int i = 0; i < 1'000; i++)
        {
            std::cout << s[0];
        }

        std::cout << s;
        std::cout << " from ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
        mtx_cout.unlock();
    };

    std::thread t1{greeter, "Hello"};
    std::thread t2{greeter, "Goodbye"};

    mtx_cout.lock();
    std::cout << "The main thread is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';
    mtx_cout.unlock();

    t1.join();
    t2.join();
}
