/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: sort with comparator
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

bool shorter(const std::string &left, const std::string &right)
{
    return left.size() < right.size();
}
} // namespace

int main()
{
    std::vector<std::string> data{"bobby", "ty", "wes"};
    print(data.begin(), data.end(), "A string vector");
    std::sort(data.begin(), data.end(), shorter);
    print(data.begin(), data.end(), "Sorted from shorter to longer");
}
