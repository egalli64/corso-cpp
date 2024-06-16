/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL forward_list
 */
#include <forward_list>
#include <iostream>
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
    std::forward_list<std::string> data{"tom", "bob", "kim"};
    print(data.cbegin(), data.cend(), "A forward list");

    data.push_front("zoe");
    data.remove("bob");
    print(data.cbegin(), data.cend(), "After push and remove");
}
