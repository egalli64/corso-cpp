/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL numeric algorithm: accumulate
 */
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    std::vector<int> values{2, 3, 7};
    std::cout << "Product of values is ";
    std::cout << std::accumulate(values.begin(), values.end(), 1, [](int a, int b) { return a * b; }) << '\n';

    std::vector<std::string> names{"Tom", "Bob", "Jon"};
    std::cout << "Concatenation of names is ";
    std::cout << std::accumulate(names.begin(), names.end(), std::string{},
                                 [](const std::string &s, const std::string &t) { return s + t; })
              << '\n';
}
