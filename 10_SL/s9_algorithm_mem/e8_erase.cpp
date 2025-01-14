/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: C++20 erase()
 * g++ -std=c++20 e8_erase.cpp
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

#if __cplusplus >= 202002L
    std::erase(values, 1);
    print(values, "After erase 1: ");
#else
    std::cout << "std::erase requirese C++20\n";
#endif
}
