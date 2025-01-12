/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: copy_if()
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

    std::copy_if(source.begin(), source.end(), std::front_inserter(destination), [](int x) { return x % 2 == 0; });
    print(destination, "After copy_if even (front): ");
    std::copy_if(source.begin(), source.end(), std::back_inserter(destination), [](int x) { return x % 2 == 0; });
    print(destination, "After copy_if even (back): ");
    std::copy_if(source.begin(), source.end(), std::inserter(destination, ++destination.begin()),
                 [](int x) { return x % 2 != 0; });
    print(destination, "After copy_if odd (@1): ");
}
