/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL list
 */
#include <iostream>
#include <list>
#include <string>

void print(const std::list<std::string> &data)
{
    for (const std::string &cur : data)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::list<std::string> empty;
    std::cout << "Size of an empty list is " << empty.size() << '\n';

    std::list<std::string> data{"tom", "bob", "kim"};
    print(data);

    data.push_front("zoe");
    data.push_back("jim");
    data.remove("bob");
    print(data);
}
