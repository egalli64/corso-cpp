/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL iterator - iterating explicitly
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int raw[]{5, 6, 42};

    std::cout << "Iterating by pointer on a raw array: ";
    for (const int *ptr = raw; ptr != raw + (sizeof(raw) / sizeof(int)); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    std::vector<std::string> values{"tom", "bob", "kim"};

    std::cout << "Iterating by const_iterator on a vector: ";
    for (auto it = values.cbegin(); it != values.cend(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
