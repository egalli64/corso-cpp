/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL iterator
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int raw[]{5, 6, 42};

    std::cout << "Range for on a raw array: ";
    for (int value : raw)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    std::cout << "Iterating by pointer on a raw array: ";
    for (int *ptr = raw; ptr != raw + (sizeof(raw) / sizeof(int)); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    std::vector<std::string> values{"tom", "bob", "kim"};

    std::cout << "Range for on an vector: ";
    for (const auto &value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    std::cout << "Iterating by const_iterator on a vector: ";
    for (auto it = values.cbegin(); it != values.cend(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
