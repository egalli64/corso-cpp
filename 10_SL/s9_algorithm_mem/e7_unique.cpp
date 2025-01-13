/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: unique() on same and on condition
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Iterable> void print(const Iterable &items, const std::string &prefix = "")
{
    std::cout << prefix << "[ ";
    for (const auto &item : items)
    {
        std::cout << item << ' ';
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<int> values{1, 1, 42, 2, 1};
    print(values, "Original: ");

    // remove then erase
    auto it = std::unique(values.begin(), values.end());
    print(values, "After leaving just unique consecutive elements: ");
    values.erase(it, values.end());
    print(values, "After erasing: ");

    // conditional (both even) unique with erase-remove idiom
    values.erase(
        std::unique(values.begin(), values.end(), [](const int x, const int y) { return x % 2 == 0 && y % 2 == 0; }),
        values.end());
    print(values, "After erase-remove not unique even: ");
}
