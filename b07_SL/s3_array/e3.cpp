/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL Array
 */
#include <iostream>
#include <array>
#include <string>

void print(const std::array<int, 4> &values, const std::string &label)
{
    std::cout << label << ": ";
    for (int cur : values)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::array<int, 4> values{6, 3, 7};
    print(values, "An array");

    // all elements implicitly initialized to 0
    std::array<int, 4> others{};
    print(others, "A zero-initialized array");

    others.fill(-1);
    print(others, "An array filled with -1");

    for (int &cur : values)
    {
        cur += 1;
    }
    print(values, "An all element increase");

    std::cout << "First element in values: " << values.front() << '\n';
    std::cout << "Last element in values: " << values.back() << '\n';

    values.swap(others);
    print(values, "Swap arrays");
}
