/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda with empty capture list
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

/**
 * @brief an increasing function
 * @param value passed by reference and increased
 */
void increase(int &value)
{
    value += 1;
}
} // namespace

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5};
    print(values.cbegin(), values.cend(), "A few values");

    std::cout << "Increase three times by function\n";
    for (int i = 0; i < 3; ++i)
    {
        for_each(values.begin(), values.end(), increase);
        print(values.cbegin(), values.cend());
    }

    std::cout << "Increase by lambda\n";
    for (int i = 0; i < 3; ++i)
    {
        for_each(values.begin(), values.end(), [](int &cur) { cur += 1; });
        print(values.cbegin(), values.cend());
    }
}
