/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - concat operators
 */
#include <iostream>
#include <string>

int main()
{
    // constructing strings
    std::string hello{"Hello"};
    std::string s = "string";

    // concatenation accepts another std::string, c-string, char
    // with a c-string
    std::string t = hello + " C++";
    std::cout << t << '\n';

    // self concatenate
    // with char
    t += ' ';
    // with another std::string
    t += s;
    std::cout << t << '\n';
}
