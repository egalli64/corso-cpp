/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: sort, stable_sort
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace
{
template <typename IT> void print(IT it, IT end, const std::string &label)
{
    std::cout << label << ": [ ";
    for (; it != end; ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "]\n";
}
} // namespace

int main()
{
    std::vector<std::string> data{"tom", "bob", "kim"};
    print(data.begin(), data.end(), "A string vector");
    std::sort(data.begin(), data.end());
    // std::stable_sort(data.begin(), data.end());
    print(data.begin(), data.end(), "Sorted");
}
