/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - subscript operator
 */
#include <iostream>
#include <string>

int main()
{
    std::string alpha{"alpha"};

    std::cout << alpha << ":\n";
    std::cout << "First char is: " << alpha[0] << '\n';
    std::cout << "Bound checking is our responsibility: " << alpha[42] << '\n';

    try
    {
        std::cout << "Use at() when in doubt ... ";
        std::cout << alpha.at(42) << '\n';
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "and try/catch its use\n";
        std::cout << "Out of range exception: " << ex.what() << '\n';
    }
}
