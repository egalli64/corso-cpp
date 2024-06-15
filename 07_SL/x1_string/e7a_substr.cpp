/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - substring
 */
#include <iostream>
#include <string>

int main()
{
    std::string alpha{"alpha"};

    // generate a substring from the current one
    std::cout << "The 'full' substring is: " << alpha.substr() << '\n';
    std::cout << "From the third char on: " << alpha.substr(2) << '\n';
    std::cout << "From the second char, sized two: " << alpha.substr(1, 2) << '\n';
    std::cout << "From the second char, wrongly sized (till the end): " << alpha.substr(1, 42) << '\n';

    std::cout << "The starting position should be in range!\n";
    try
    {
        alpha.substr(-42);
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "out of range: " << ex.what() << '\n';
    }
}
