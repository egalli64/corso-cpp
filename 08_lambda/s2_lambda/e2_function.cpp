/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * sort as higher order function
 * function as first class variable
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
template <typename IT> void print(const std::string &message, IT begin, IT end)
{
    std::cout << message << ": ";
    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

/**
 * @brief a sorting strategy
 * @return true if the first parameter should be before the second one
 */
bool largerFirst(int left, int right)
{
    return left > right;
}
} // namespace

int main()
{
    std::vector<int> data{34, 12, 3, 8, 5, 43};
    print("original data", data.cbegin(), data.cend());

    std::sort(data.begin(), data.end());
    print("plain sort", data.cbegin(), data.cend());

    std::sort(data.begin(), data.end(), largerFirst);
    print("sort by function, larger first", data.cbegin(), data.cend());
}
