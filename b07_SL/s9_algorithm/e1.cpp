/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: sort
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string> &items, const std::string &label)
{
    std::cout << label << " [ ";
    for (const auto &item : items)
    {
        std::cout << item << ' ';
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<std::string> data{"tom", "bob", "kim"};
    print(data, "A string vector");
    sort(data.begin(), data.end());
    stable_sort(data.begin(), data.end());
    print(data, "Sorted");
}
