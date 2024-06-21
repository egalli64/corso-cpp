/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - char vs string
 */
#include <iostream>

int main()
{
    char c = 'x';
    std::cout << "A character: " << c << '\n';

    std::string s = "Hello";
    std::cout << "A C++ string: " << s << '\n';

    const char *s2 = "Hello, again!";
    std::cout << "A C-string: " << s2 << '\n';
}
