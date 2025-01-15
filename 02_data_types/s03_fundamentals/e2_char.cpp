/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - char
 */
#include <iostream>

int main()
{
    // characters are actually integers, too
    char c = 'x';
    std::cout << "A character: " << c << '\n';

    int i_widened = c;
    std::cout << "A char implicitly converted to int: " << i_widened << '\n';

    char other = i_widened;
    std::cout << "A int implicitly converted to char: " << other << '\n';
}
