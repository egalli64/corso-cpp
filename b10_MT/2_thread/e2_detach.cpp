/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * The main thread could detach from a child thread, so that it could terminate without waiting for it
 * It should call pthread_exit (Linux) to terminate safely without killing the other threads
 *
 * g++ -pthread -o a.out e2_detach.cpp
 */
#include <iostream>
#include <thread>

namespace {
    void a_function() {
        std::cout << "Enter task\n";
        std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });
        std::cout << "Task done!\n";
    }
}

int main() {
    std::thread t1{ a_function };
    std::cout << "Do not wait for task\n";
    t1.detach();

    std::cout << "Main done!\n";
    pthread_exit(nullptr);
}
