/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Joining thread C++20 std::jthread
 *
 * g++ -pthread -std=c++20 -Wall -o a.out e3_jthread.cpp
 */
#include <cstdlib>
#include <iostream>
#include <thread>

void shutdown()
{
    std::cout << "Shutting down\n";
}

int main()
{
    std::atexit(shutdown);
    std::jthread jt{[] { std::cout << "Hello from child thread\n"; }};

    std::cout << "Hello from main thread\n";
}
