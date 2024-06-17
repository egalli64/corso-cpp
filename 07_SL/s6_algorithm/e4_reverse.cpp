/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: reverse
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
    std::vector<std::string> data{"tom", "bob", "kim"};
    print(data.cbegin(), data.cend(), "A string container");
    reverse(data.begin(), data.end());
    print(data.cbegin(), data.cend(), "Reversed");
}
