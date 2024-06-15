/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - replace
 */
#include <iostream>
#include <string>

int main()
{
    std::string alpha{"alpha"};
    std::cout << "Replacing in " << alpha;
    std::cout << " three chars from the second with \"d\": ";
    std::cout << alpha.replace(1, 3, "d") << '\n';

    std::string beta{"beta"};
    std::string tail{"elgeuse"};
    std::cout << "Replacing in " << beta;
    std::cout << " the last char with another string: ";
    std::cout << beta.replace(3, 1, tail) << '\n';
}
