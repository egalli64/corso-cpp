/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Race condition
 *
 * g++ -pthread -o a.out e2_race.cpp
 */
#include <iostream>
#include <thread>

int main()
{
    int result = 0;
    // increasing/decreasing the count value could introduce/fix the problem!
    const int count = 50'000;

    std::thread t{[&result] {
        for (int i = 0; i < count; ++i)
        {
            result++;
        }
    }};

    for (int i = 0; i < count; ++i)
    {
        result++;
    }

    t.join();
    if (result != count * 2)
    {
        std::cout << "Problematic data race: " << result << "!\n";
    }
    else
    {
        std::cout << "No problem!\n";
    }
}
