/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: replace_if
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
    std::vector<std::string> names{"Tom", "Tony", "Kim", "Liza"};
    print(names, "The names: ");

    std::cout << "Replace the strings sized 4\n";

    // loop
    for (std::string &name : names)
    {
        if (name.size() == 4)
        {
            name = "____";
        }
    }
    print(names, "No replace_if (explicit loop): ");

    std::replace_if(names.begin(), names.end(), [](const std::string &x) { return x.size() == 4; }, "****");
    print(names, "replace_if by lambda expression: ");
}
