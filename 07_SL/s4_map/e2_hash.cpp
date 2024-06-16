/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL map
 */
#include <iostream>
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
    std::unordered_map<std::string, double> data{{"tom", 32.18}, {"bob", 44.11}};
    print(data.begin(), data.end(), "A (hash based) map");

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

    // associative array syntax, could be confusing
    std::cout << "bob value is: " << data["bob"] << '\n';
    std::cout << "Bob value is: " << data["Bob"] << " (when missing, use the type default)\n";
    print(data.begin(), data.end(), "Now there are two bobs )");

    // classic syntax, more robust
    if (auto it = data.find("kim"); it != data.end())
    {
        std::cout << "kim value (find) is: " << it->second << '\n';
    }
    else
    {
        std::cout << "unexpected!\n";
    }

    auto it = data.find("Kim");
    std::cout << (it == data.end() ? "kim not found" : "unexpected!") << '\n';
    print(data.begin(), data.end(), "No duplicated kim (");

    // robustness by exception
    std::cout << "tom value (at) is: " << data.at("tom") << '\n';

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
