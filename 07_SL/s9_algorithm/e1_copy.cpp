/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: copy
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
} // namespace

int main()
{
    std::vector<int> values{7, 3, 1, 2};
    print(values.cbegin(), values.cend(), "A vector");

    std::vector<int> other(5);
    print(other.cbegin(), other.cend(), "Another vector");

    // a "normal" output operator let the algorithm to override values - they should exists!
    std::copy(values.begin(), values.end(), other.begin());
    print(other.cbegin(), other.cend(), "Other after copy");

    std::vector<int> destination({-1, -1});
    print(destination.cbegin(), destination.cend(), "The copy destination with back inserter");

    // safer, the back_inserter push the new elements back
    std::copy(values.cbegin(), values.cend(), std::back_inserter(destination));
    print(destination.cbegin(), destination.cend(), "destination after copy back");
}
