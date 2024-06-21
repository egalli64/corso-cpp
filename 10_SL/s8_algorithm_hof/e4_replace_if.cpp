/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: replace_if
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

bool is_odd(int value)
{
    return value % 2;
}
} // namespace

int main()
{
    std::vector<int> values{7, 22, 11, 26};
    print(values.cbegin(), values.cend(), "A vector");

    std::replace_if(values.begin(), values.end(), is_odd, -1);
    print(values.cbegin(), values.cend(), "Replaced");
}
