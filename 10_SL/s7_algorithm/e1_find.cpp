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

    // find in an interval a value
    for (int target = 1; target <= 2; ++target)
    {
        if (auto it = std::find(values.begin(), values.end(), target); it == values.end())
        {
            std::cout << target << ": not found\n";
        }
        else
        {
            std::cout << *it << ": found\n";
        }
    }
}
