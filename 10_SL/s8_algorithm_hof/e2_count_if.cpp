/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: count_if
 */
#include <algorithm>
#include <iostream>
#include <vector>

namespace
{
bool is_odd(int value)
{
    return value % 2;
}
} // namespace

int main()
{
    std::vector<int> values{1, 2, 73, 54, 19};

    int result = std::count_if(values.begin(), values.end(), is_odd);
    std::cout << result << " odd elements found\n";
}
