/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{7, 2, 12, 54, 34};

    // find a value in the passed interval
    int target = 12;
    if (std::find(values.begin(), values.end(), target) != values.end())
    {
        std::cout << target << " found\n";
    }
    else
    {
        std::cout << "unexpected\n";
    }

    target += 1;
    if (std::find(values.begin(), values.end(), target) == values.end())
    {
        std::cout << target << " not found\n";
    }
    else
    {
        std::cout << "unexpected\n";
    }
}
