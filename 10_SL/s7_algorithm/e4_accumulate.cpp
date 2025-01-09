/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL numeric algorithm: accumulate
 */
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> values{7, 2, 12, 54, 34};

    // accumulate (adding) in an interval starting from value zero
    std::cout << "Sum of values is ";
    std::cout << accumulate(values.begin(), values.end(), 0) << '\n';

    std::cout << "Sum of internal values is ";
    std::cout << accumulate(values.begin() + 1, values.end() - 1, 0) << '\n';
}
