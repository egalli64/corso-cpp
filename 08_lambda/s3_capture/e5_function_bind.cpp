/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Function binding
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

namespace
{
/**
 * @brief a utility function
 */
template <typename IT> void print(IT begin, IT end, const std::string &message = "")
{
    std::cout << message;
    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

/**
 * @brief a function meant to be bound to a HOF
 */
void increaseValueBy(int &value, int delta)
{
    value += delta;
}

/**
 * @brief a function meant to be bound to a HOF
 */
void increaseByValue(int delta, int &value)
{
    value += delta;
}
} // namespace

int main()
{
    std::vector<int> values{1, 2, 3};
    print(values.cbegin(), values.cend(), "A few values: ");

    std::cout << "Increase by [0 .. 3) using for_each + function (placeholder 1st)\n";
    for (int i = 0; i < 3; ++i)
    {
        for_each(values.begin(), values.end(), std::bind(increaseValueBy, std::placeholders::_1, i));
        print(values.cbegin(), values.cend());
    }

    std::cout << "Increase by [0 .. 3) using for_each + function (placeholder 2nd)\n";
    for (int i = 0; i < 3; ++i)
    {
        for_each(values.begin(), values.end(), std::bind(increaseByValue, i, std::placeholders::_1));
        print(values.cbegin(), values.cend());
    }
}
