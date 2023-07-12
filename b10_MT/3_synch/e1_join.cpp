/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Synchronization by join
 *
 * g++ -pthread -o a.out e1_join.cpp
 */
#include <iostream>
#include <thread>

int main()
{
    int result = 0;
    std::cout << "Result is " << result << '\n';

    std::thread t{[&result] { result = 42; }};
    t.join();

    std::cout << "Result now is " << result << '\n';
}
