/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * sort as higher order function
 * lambda as first class variable
 */
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

namespace
{
    void print(const std::string &message, const std::vector<int> &data)
    {
        std::cout << message << ": ";
        copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }
}

int main()
{
    std::vector<int> data{34, 12, 3, 8, 5, 43};
    print("original data", data);

    auto order = [](int left, int right)
    {
        return left > right;
    };

    std::sort(data.begin(), data.end(), order);
    print("reversed sort by lambda", data);
}
