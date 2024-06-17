/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find w/ pointers
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int values[]{7, 2, 12, 54, 34};
    constexpr int size = sizeof(values) / sizeof(int);

    // find a value in the passed interval
    int target = 12;
    if (std::find(values, values + size, target) != values + size)
    {
        std::cout << target << " found\n";
    }
    else
    {
        std::cout << "unexpected\n";
    }

    target += 1;
    if (std::find(values, values + size, target) == values + size)
    {
        std::cout << target << " not found\n";
    }
    else
    {
        std::cout << "unexpected\n";
    }
}
