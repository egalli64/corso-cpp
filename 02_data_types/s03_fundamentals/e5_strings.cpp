/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - strings
 */
#include <iostream>

int main()
{
    std::string s = "Hello";
    std::cout << "A string: " << s << '\n';

    const char *ls = "Legacy hello";
    std::cout << "A legacy string: " << ls << '\n';
}
