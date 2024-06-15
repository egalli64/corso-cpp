/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - size / length
 */
#include <iostream>
#include <string>

int main()
{
    std::string alpha{"alpha"};

    std::cout << alpha << ' ' << "size is " << alpha.size() << '\n';
    std::cout << alpha << ' ' << "length is " << alpha.length() << '\n';
}
