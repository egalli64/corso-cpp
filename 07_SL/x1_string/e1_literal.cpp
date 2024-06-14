/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string
 */
#include <iostream>
#include <string>
#include <type_traits>

using namespace std::literals::string_literals;

int main()
{
    if (std::is_same<std::string, std::basic_string<char>>::value)
    {
        std::cout << "std::string is a typedef of std::basic_string<char>\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    auto s = "Hello C++ string"s;
    std::cout << "Literal std::string: " << s << '\n';

    std::string t{"Hello C++ string"};
    std::cout << "From literal c-string to std::string: " << t << '\n';
}