/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL string: concatenation
 */
#include <iostream>
#include <string>

int main()
{
    std::string s = "one";
    std::cout << "String s is " << s << '\n';

    std::string t = "two";
    std::cout << "String t is " << t << '\n';

    t += s;
    std::cout << "Now string t is " << t << '\n';

    std::string u = s + t;
    std::cout << "String u is " << u << '\n';
}
