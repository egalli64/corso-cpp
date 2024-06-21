/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: replace
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace
{
template <typename IT> void print(IT cur, IT end, const std::string &label)
{
    std::cout << label << " [ ";
    for (; cur != end; ++cur)
    {
        std::cout << *cur << ' ';
    }
    std::cout << "]\n";
}
} // namespace

int main()
{
    std::vector<int> values{7, 23, 11, 23};
    print(values.cbegin(), values.cend(), "A vector");

    std::replace(values.begin(), values.end(), 23, -1);
    print(values.cbegin(), values.cend(), "Replaced");
}
