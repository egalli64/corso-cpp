/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: transform()
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
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
    std::vector<int> source{1, 2, 3};
    print(source, "The source: ");

    std::list<int> destination{};
    print(destination, "The transformation (before): ");

    std::transform(source.begin(), source.end(), std::back_inserter(destination), [](int x) { return x * 2; });
    print(destination, "The transformation (after): ");
}
