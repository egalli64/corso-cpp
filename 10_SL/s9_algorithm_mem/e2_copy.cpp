/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: copy()
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
    print(destination, "The destination: ");

    std::copy(source.begin(), source.end(), std::front_inserter(destination));
    print(destination, "After copy (front): ");
    std::copy(source.begin(), source.end(), std::back_inserter(destination));
    print(destination, "After copy (back): ");
    std::copy(source.begin(), source.end(), std::inserter(destination, ++destination.begin()));
    print(destination, "After copy (@1): ");
}
