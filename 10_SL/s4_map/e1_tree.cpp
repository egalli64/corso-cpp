/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL map (BST based)
 */
#include <iostream>
#include <map>
#include <string>

void print(const std::map<std::string, double> &items)
{
    for (const auto &item : items)
    {
        std::cout << item.first << ' ' << item.second << '\n';
    }
    std::cout << '\n';
}

int main()
{
    std::map<std::string, double> data{{"tom", 32.18}, {"bob", 44.11}, {"kim", 98.03}};
    data.insert({"mia", 91.12});
    data.emplace("jim", 12.23);
    print(data);

    // C++17
    if (auto it = data.find("bob"); it != data.end())
    {
        std::cout << "find bob: " << it->second << '\n';
    }
    else
    {
        std::cout << "bob not found\n";
    }

    // pre-C++ 17
    {
        auto it = data.find("bob");
        if (it != data.end())
        {
            std::cout << "find bob: " << it->second << '\n';
        }
        else
        {
            std::cout << "bob not found\n";
        }
    }

    std::cout << "at tom: " << data.at("tom") << '\n';

    try
    {
        double joe = data.at("joe");
        std::cout << joe << '\n';
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "Out of range calling " << ex.what() << " on joe" << '\n';
    }
}
