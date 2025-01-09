/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL iterator - iterating implicitly by range for
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int raw[]{5, 6, 42};

    std::cout << "Range for on a raw array: ";
    for (const int value : raw)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    std::vector<std::string> values{"tom", "bob", "kim"};

    std::cout << "Range for on an vector: ";
    for (const auto &value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
