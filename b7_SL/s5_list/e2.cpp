/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL forward_list
 */
#include <iostream>
#include <forward_list>
#include <string>

void print(const std::forward_list<std::string> &data)
{
    for (const std::string &cur : data)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::forward_list<std::string> data{"tom", "bob", "kim"};
    print(data);

    data.push_front("zoe");
    data.remove("bob");
    print(data);
}
