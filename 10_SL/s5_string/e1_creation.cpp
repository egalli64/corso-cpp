/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL string: creation / assignment
 */
#include <iostream>
#include <string>

int main()
{
    std::string s = "one";
    std::cout << "String s is " << s << '\n';

    std::basic_string<char> t = "two";
    std::cout << "String t is " << t << '\n';

    t = s;
    std::cout << "Now string t is " << t << '\n';
}
