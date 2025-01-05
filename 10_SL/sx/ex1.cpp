/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * 1: given a vector of numbers create a new container containing the squared values of the original vector
 */

#include "my_print.h"
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> data{2, 5, 6, 3, 4, 1};

    print(data.begin(), data.end(), "Original data");

    // inplace
    // std::for_each(data.begin(), data.end(), [](int& x) { x *= x; });

    std::vector<int> squared;
    // set the capacity as required
    // squared.reserve(data.size());

    // map the data by transform + lambda, push the result by back_inserter to the other vector
    std::transform(data.begin(), data.end(), std::back_inserter(squared), [](int n) { return n * n; });
    print(squared.begin(), squared.end(), "Squared data");
}
