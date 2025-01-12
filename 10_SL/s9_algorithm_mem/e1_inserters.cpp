/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: front_inserter(), back_inserter(), inserter()
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

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
    std::list<std::string> values{};
    print(values, "The original vector: ");

    // notice: it doesn't make sense using inserters in this way
    *std::front_inserter(values) = "front_inserted";
    *std::back_inserter(values) = "back_inserted";
    *std::inserter(values, ++values.begin()) = "inserted@1";

    print(values, "After insertions: ");
}
