/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: transform
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace
{
template <typename IT> void print(IT cur, IT end, const std::string &label)
{
    std::cout << label << ": [ ";
    for (; cur != end; ++cur)
    {
        std::cout << *cur << ' ';
    }
    std::cout << "]\n";
}

int square(int x)
{
    return x * x;
}
} // namespace

int main()
{
    std::vector<int> values{3, 0, 1, 2};
    print(values.cbegin(), values.cend(), "A vector");

    // a "normal" output iterator let the algorithm to override values - they should exists!
    std::transform(values.cbegin(), values.cend(), values.begin(), square);
    print(values.cbegin(), values.cend(), "After transformation");

    std::vector<int> squared;
    std::transform(values.cbegin(), values.cend(), std::back_inserter(squared), square);
    print(values.cbegin(), values.cend(), "The source");
    print(squared.cbegin(), squared.cend(), "The destination");
}
