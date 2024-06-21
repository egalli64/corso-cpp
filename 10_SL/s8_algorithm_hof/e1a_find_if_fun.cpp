/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find_if by function pointer
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace
{
bool hasSizeEqualToFour(const std::string &s)
{
    return s.size() == 4;
}
} // namespace

int main()
{
    std::vector<std::string> values{"Tom", "Kim", "Tony", "Liza"};

    std::cout << "Find first string sized 4: ";
    // auto it = find_if(values.begin(), values.end(), hasSizeEqualToFour);
    // std::cout << (it != values.end() ? *it : "Not found!") << '\n';

    if (auto it = find_if(values.begin(), values.end(), hasSizeEqualToFour); it != values.end())
    {
        std::cout << *it << '\n';
    }
    else
    {
        std::cout << "unexpected\n";
    }
}
