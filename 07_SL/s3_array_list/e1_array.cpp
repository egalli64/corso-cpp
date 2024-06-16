/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::array
 */
#include <array>
#include <iostream>

namespace
{
/**
 * @brief a simple template function to print all the elements in an iterval
 *
 * @param it iterator to the first element to be printed
 * @param end iterator to the end sentinel
 * @param label a heading message to be printed
 */
template <typename IT> void print(IT it, IT end, const std::string &label)
{
    std::cout << label << ": ";
    while (it != end)
    {
        std::cout << *it << ' ';
        it += 1;
    }
    std::cout << '\n';
}
} // namespace

int main()
{
    std::array<int, 3> uninitialized;
    // using non-const iterators is a bit sloppy
    print(uninitialized.begin(), uninitialized.end(), "An uninitialized array");

    std::array<int, 6> values{6, 4, 3};
    // better, const iterators are passed
    print(values.cbegin(), values.cend(), "An initialized array");

    std::cout << "loop-increase by iterator: ";
    // auto is here std::array<int, 6>::iterator
    for (auto it = values.begin(); it != values.end(); ++it)
    {
        std::cout << ++(*it) << ' ';
    }
    std::cout << '\n';

    // all elements implicitly initialized to 0
    std::array<int, 6> others{};
    print(others.cbegin(), others.cend(), "An-other array - zero-initialized");

    others.fill(-1);
    print(others.cbegin(), others.cend(), "Now the other array is filled with -1");

    values.swap(others);
    print(others.cbegin(), others.cend(), "After swap other contains");
    print(values.cbegin(), values.cend(), "And values contains");
}
