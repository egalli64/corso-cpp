/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * sort as higher order function
 * lambda as first class variable
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace
{
/**
 * @brief a utility function
 */
void print(const std::string &message, const std::vector<int> &data)
{
    std::cout << message << ": ";
    std::copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
} // namespace

int main()
{
    std::vector<int> data{34, 12, 3, 8, 5, 43};
    print("original data", data);

    // auto order = [](int left, int right) { return left > right; };
    // std::sort(data.begin(), data.end(), order);

    std::sort(data.begin(), data.end(), [](int a, int b) { return a > b; });
    print("reversed sort by lambda", data);
}
