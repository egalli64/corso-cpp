/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - c_str, data
 */
#include <iostream>
#include <string>

int main()
{
    std::string alpha{"alpha"};
    std::cout << "Working on " << alpha << '\n';

    std::cout << "Accessing the string data by const c-string: [ ";
    const char *cs = alpha.c_str();
    while (*cs != '\0')
    {
        std::cout << *cs << ' ';
        cs += 1;
    }
    std::cout << "]\n";

    std::cout << "Accessing the string data by mutable c-string: ";
    char *ds = alpha.data();
    while (*ds != '\0')
    {
        *ds += 1;
        ds += 1;
    }
    std::cout << alpha << '\n';
}
