/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: accumulate with binary operation
 */
#include <iostream>
#include <numeric>
#include <vector>

namespace
{
int multiply(int a, int b)
{
    return a * b;
}
} // namespace

int main()
{
    std::vector<int> values{7, 2, 12, 54, 34};

    // accumulate (multiply all values up) in an interval starting from value one
    int prod = std::accumulate(values.cbegin(), values.cend(), 1, multiply);
    std::cout << "Product of values is " << prod << '\n';
}
