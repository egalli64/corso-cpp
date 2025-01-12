/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: remove()
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
    std::vector<int> values{1, 2, 3, 2, 1};
    print(values, "Original: ");

    // remove then erase
    auto it = std::remove(values.begin(), values.end(), 2);
    print(values, "After remove on 2: ");
    values.erase(it, values.end());
    print(values, "After erase on the iterator returned by remove: ");

    // usually combined in the erase-remove idiom
    values.erase(std::remove(values.begin(), values.end(), 1), values.end());
    print(values, "After erase-remove on 1: ");
}
