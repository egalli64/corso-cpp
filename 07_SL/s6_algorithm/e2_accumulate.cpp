/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: accumulate
 */
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> values{7, 2, 12, 54, 34};

    // accumulate (adding all values up) in an interval starting from value zero
    int sum = std::accumulate(values.cbegin(), values.cend(), 0);
    std::cout << "Sum of values is " << sum << '\n';

    // we actually get random access iterators from vector
    sum = std::accumulate(values.cbegin() + 1, values.cend() - 1, 0);
    std::cout << "Sum of internal values is " << sum << '\n';
}
