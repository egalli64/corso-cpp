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
    std::vector<int> values{1, 2, 1, 54, 1};

    for (int i = 0; i < 2; ++i)
    {
        int result = std::count(values.begin(), values.end(), i);
        std::cout << result << " occurrences of " << i << " found\n";
    }
}
