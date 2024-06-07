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
    // given a prefix provided elsewhere
    std::string prefix{"-> "};
    std::vector<std::string> names{"Tom", "Bob", "Kim"};

    // create a lambda that captures the prefix
    auto print = [prefix](const std::string &s) -> void { std::cout << prefix << s << '\n'; };
    print("A lambda is a callable");

    std::cout << "Passing a lambda to a function:\n";
    // pass the lambda to a HOF that uses it
    std::for_each(names.begin(), names.end(), print);
}
