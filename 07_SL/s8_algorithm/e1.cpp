/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find, accumulate
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> values{7, 2, 12};

    // find in an interval a value
    int target{2};
    auto itTwo = find(values.begin(), values.end(), target);
    std::cout << target << (itTwo == values.end() ? " not " : " ") << "found\n";

    // accumulate (adding) in an interval starting from value zero
    int sum = accumulate(values.begin(), values.end(), 0);
    std::cout << "Sum of values is " << sum << '\n';
}
