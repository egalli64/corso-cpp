/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find on a raw array
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int values[]{7, 2, 12, 54, 34};

    // find in an interval a value
    for (int target = 34; target <= 35; ++target)
    {
        int *end = values + (sizeof(values) / sizeof(int));
        if (auto it = std::find(values, end, target); it == end)
        {
            std::cout << target << ": not found\n";
        }
        else
        {
            std::cout << *it << ": found\n";
        }
    }
}
