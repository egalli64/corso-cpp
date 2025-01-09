/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: count
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{7, 8, 8, 7, 7};

    // find in an interval a value
    for (int target = 7; target <= 9; ++target)
    {
        std::cout << "Occurrences of " << target << ": ";
        std::cout << std::count(values.begin(), values.end(), target) << '\n';
    }
}
