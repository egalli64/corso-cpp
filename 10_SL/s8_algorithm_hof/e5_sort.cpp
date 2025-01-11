/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: sort
 */
#include <algorithm>
#include <iostream>
#include <string>
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
    std::vector<std::string> data{"toby", "billy", "bob"};
    print(data, "A string vector: ");
    std::sort(data.begin(), data.end(), [](const std::string &s, const std::string &t) { return s.size() < t.size(); });
    print(data, "Sorted by size (natural): ");

    std::sort(data.begin(), data.end(), [](const std::string &s, const std::string &t) { return s.size() > t.size(); });
    print(data, "Sorted by size (descending): ");
}
