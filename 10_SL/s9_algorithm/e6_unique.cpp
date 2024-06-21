/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: unique - erase
 */
#include <algorithm>
#include <iostream>
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
} // namespace

int main()
{
    std::vector<int> values{7, 23, 23, 11, 23, 12};
    print(values.cbegin(), values.cend(), "A vector");

    auto end = std::unique(values.begin(), values.end());
    print(values.cbegin(), values.cend(), "After removing consecutive duplicates");
    print(end, values.end(), "The tail to be erased");

    values.erase(end, values.end());
    print(values.cbegin(), values.cend(), "After erasing");
}
