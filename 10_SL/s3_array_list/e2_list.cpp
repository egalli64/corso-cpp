/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL list
 */
#include <iostream>
#include <list>
#include <string>

namespace
{
/**
 * @brief a simple template function to print all the elements in an iterval
 *
 * @param it iterator to the first element to be printed
 * @param end iterator to the end sentinel
 * @param label a heading message to be printed
 */
template <typename IT> void print(IT it, IT end, const std::string &label)
{
    std::cout << label << ": ";
    for (; it != end; ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
} // namespace

int main()
{
    std::list<std::string> empty;
    std::cout << "Size of an empty list is " << empty.size() << '\n';

    std::list<std::string> data{"tom", "bob", "kim"};
    print(data.begin(), data.end(), "A list");

    std::cout << "The first element is " << data.front() << '\n';
    std::cout << "The last element is " << data.back() << '\n';

    data.push_front("zoe");
    data.emplace_back("jim");
    // remove all the "bob" in list
    data.remove("bob");
    print(data.begin(), data.end(), "After push, emplace and remove");
}
