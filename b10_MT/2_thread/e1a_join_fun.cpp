/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Executing code on different threads shared resources should be protected!
 * - creating a std::thread starts the passed function in a new thread
 * - join on thread to wait for its termination, otherwise the pending threads will be killed
 *
 * g++ -pthread -o a.out e1a_join_fun.cpp
 */
#include <iostream>
#include <thread>

namespace
{
    void loop1KOn(char c)
    {
        for (int i = 0; i < 1'000; i++)
        {
            std::cout << c;
        }
    }

    void greeter(const std::string &greet)
    {
        loop1KOn(greet[0]);
        std::cout << greet;
        std::cout << " from thread ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
    }
}

int main()
{
    std::cout << "Warning! This code is not thread safe!\n";

    std::thread t1{greeter, "Hello"};
    std::thread t2{greeter, "Goodbye"};

    std::string message {"Welcome"};
    loop1KOn(message[0]);
    std::cout << message << " from the main thread ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';

    std::cout << "The access ";
    std::cout << "to the shared ";
    std::cout << "resource cout ";
    std::cout << "is not protected!";
    std::cout << '\n';

    t1.join();
    t2.join();

    std::cout << "Done!\n";
}
