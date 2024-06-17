/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL maps - insert
 */
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

namespace
{
/**
 * @brief a simple template function to print all the pairs in an iterval
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
    std::map<std::string, double> data{{"tom", 32.18}, {"bob", 44.11}};
    print(data.begin(), data.end(), "A map");

    // associative array syntax, last wins
    data["kim"] = 15.15;
    data["kim"] = 15.51;

    // classic syntax, first wins
    data.insert({"mia", 91.12});
    data.insert({"mia", 91.19});

    // emplacing, first wins
    data.emplace("jim", 12.23);
    data.emplace("jim", 21.32);

    // C++17, last wins
    data.insert_or_assign("syd", 27.27);
    data.insert_or_assign("syd", 27.72);

    print(data.begin(), data.end(), "More pairs in");
}
