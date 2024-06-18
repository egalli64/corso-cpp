/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: copy_if
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

bool is_odd(int x)
{
    return x % 2;
}
} // namespace

int main()
{
    std::vector<int> values{7, 4, 1, 2};
    print(values.cbegin(), values.cend(), "A vector");

    std::vector<int> other(2);
    print(other.cbegin(), other.cend(), "Another vector");

    // a "normal" output operator let the algorithm to override values - they should exists!
    std::copy_if(values.begin(), values.end(), other.begin(), is_odd);
    print(other.cbegin(), other.cend(), "Other after back insertion of odd values");

    std::vector<int> destination({-1, -1});
    print(destination.cbegin(), destination.cend(), "The copy destination for inserter after first");

    // safer, the back_inserter push the new elements back
    std::copy_if(values.cbegin(), values.cend(), std::inserter(destination, destination.begin() + 1), is_odd);
    print(destination.cbegin(), destination.cend(), "destination after insertion");
}
