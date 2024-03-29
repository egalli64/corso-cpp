/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL Array
 */
#include <array>
#include <iostream>

void print(const std::array<int, 3> &data)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::array<int, 3> uninitialized;
    std::cout << "classic for loop on an uninitialized array: ";
    print(uninitialized);

    std::array<int, 6> values{6, 4, 3};
    std::cout << "loop by const iterator: ";
    // auto here is std::array<int, 6>::const_iterator
    for (auto it = values.cbegin(); it != values.cend(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    std::cout << "loop-increase by iterator: ";
    // auto here is std::array<int, 6>::iterator
    for (auto it = values.begin(); it != values.end(); ++it)
    {
        std::cout << ++(*it) << ' ';
    }
    std::cout << '\n';

    std::cout << "range-for by value: ";
    for (int cur : values)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';

    std::cout << "range-for by const ref: ";
    for (const int &cur : values)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';
}
