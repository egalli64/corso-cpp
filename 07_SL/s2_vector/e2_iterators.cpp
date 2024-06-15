/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector - size, [], front, back, and iterators
 */
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{6, 4, 3};

    std::cout << "classic for loop on a vector (uncommon): ";
    for (std::vector<int>::size_type i = 0; i < values.size(); ++i)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << '\n';

    // expect a segmentation fault if the vector is empty
    std::cout << "First element is: " << values.front() << '\n';
    std::cout << "Last element is: " << values.back() << '\n';

    std::cout << "loop by const iterator: ";
    for (auto it = values.cbegin(); it != values.cend(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    std::cout << "loop-increase by iterator: ";
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

    std::cout << "range-for by const ref (not useful on int): ";
    for (const int &cur : values)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';
}
