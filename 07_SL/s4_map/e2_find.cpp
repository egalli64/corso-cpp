/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL map - find
 */
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

namespace
{
/**
 * @brief a simple template function to print all the map pairs in an iterval
 *
 * @param it iterator to the first pair to be printed
 * @param end iterator to the end sentinel
 * @param label a heading message to be printed
 */
template <typename IT> void print(IT it, IT end, const std::string &label)
{
    std::cout << label << ": ";
    for (; it != end; ++it)
    {
        std::cout << "{ " << it->first << ", " << it->second << " } ";
    }
    std::cout << '\n';
}
} // namespace

int main()
{
    // use std::map (BST) or std::unordered_map (hashtable)
    std::unordered_map<std::string, double> data{{"tom", 32.18}, {"bob", 44.11}};
    print(data.begin(), data.end(), "A map");

    // associative array syntax, could be confusing
    std::cout << "bob value is: " << data["bob"] << '\n';
    std::cout << "Bob value is: " << data["Bob"] << " (when missing, use the type default)\n";
    print(data.begin(), data.end(), "Now there are two bobs )");

    // classic syntax, more robust
    if (auto it = data.find("tom"); it != data.end())
    {
        std::cout << "tom value (find) is: " << it->second << '\n';
    }
    else
    {
        std::cout << "unexpected!\n";
    }

    auto it = data.find("Tom");
    std::cout << (it == data.end() ? "Tom not found" : "unexpected!") << '\n';
    print(data.begin(), data.end(), "No duplicated tom (");

    // robustness by exception
    try
    {
        // this one should work
        std::cout << "tom value (at) is: " << data.at("tom") << '\n';
        // this one should fail
        std::cout << "Finding joe (at) ... ";
        std::cout << data.at("joe") << '\n';
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "out of range calling " << ex.what() << '\n';
    }
}
