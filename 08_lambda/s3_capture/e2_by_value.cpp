/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda capturing a variable by value
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
template <typename IT> void print(IT begin, IT end, const std::string &message = "")
{
    std::cout << message << ": ";
    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
} // namespace

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6};
    print(values.cbegin(), values.cend(), "A few values");

    std::cout << "Increase by [0 .. 3) using for_each + lambda, capturing by value\n";
    for (int i = 0; i < 3; ++i)
    {
        for_each(values.begin(), values.end(), [i](int &cur) { cur += i; });
        print(values.cbegin(), values.cend());
    }

    std::cout << "Increase always by 0! The capture is done when the lambda is created\n";
    int i = 0;
    auto wrong = [i](int &cur) { cur += i; };

    while (i < 3)
    {
        for_each(values.begin(), values.end(), wrong);
        print(values.cbegin(), values.cend());
        i += 1;
    }
}
