/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Exercise: an algorithm to square the elements in the passed interval
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

template <typename IT> void square(IT it, IT end)
{
    for (; it != end; ++it)
    {
        *it = (*it) * (*it);
    }
}

int main()
{
    std::vector<int> values{7, 3, 11, 3};
    print(values.cbegin(), values.cend(), "A vector");

    square(values.begin(), values.end());
    print(values.cbegin(), values.cend(), "Squared");
}
