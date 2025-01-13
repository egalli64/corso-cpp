/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: remove_if()
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
    std::vector<int> values{1, 2, 42, 2, 1};
    print(values, "Original: ");

    // remove then erase
    auto it = std::remove_if(values.begin(), values.end(), [](const int x) { return x > 10; });
    print(values, "After remove if larger than 10: ");
    values.erase(it, values.end());
    print(values, "After erasing: ");

    // usually combined in the erase-remove idiom
    values.erase(std::remove_if(values.begin(), values.end(), [](const int x) { return x % 2 != 0; }), values.end());
    print(values, "After erase-remove odd: ");
}
