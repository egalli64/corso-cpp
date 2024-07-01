/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda capturing a variable by reference
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

    std::cout << "Capturing by reference (be careful with this one!)\n";
    int i = 0;
    auto risky = [&i](int &cur) { cur += i; };

    while (i < 3)
    {
        for_each(values.begin(), values.end(), risky);
        print(values.cbegin(), values.cend());
        i += 1;
    }
}
