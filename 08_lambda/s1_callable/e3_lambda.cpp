/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * callable: lambda
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    auto print = [](const std::string &s) { std::cout << "-> " << s << '\n'; };

    print("A lambda is a callable");

    std::vector<std::string> names{"Tom", "Bob", "Kim"};
    std::cout << "Passing a lambda to a function:\n";
    std::for_each(names.begin(), names.end(), print);

    // usually a lambda expression is consumed in-place
    std::for_each(names.begin(), names.end(), [](const std::string &s) { std::cout << "... " << s << '\n'; });
}
