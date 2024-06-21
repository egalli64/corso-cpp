/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - integral vs real
 */
#include <iostream>

int main()
{
    // optional digit separator C++14
    int i = 49'385;
    std::cout << "An int: " << i << '\n';

    double d = 3.141'592'653'500;
    std::cout << "A double: " << d << '\n';

    //  Hexadecimal notation
    signed short int ssi = 0xFFFF;
    unsigned short int usi = 0xFFFF;
    std::cout << "A signed short integer: " << ssi << " and an unsigned short int: " << usi << '\n';

    // characters are actually integers, too
    char c = 'x';
    std::cout << "A character: " << c << '\n';

    int i_widened = c;
    std::cout << "A char implicitly converted to int: " << i_widened << '\n';

    char other = i_widened;
    std::cout << "A int implicitly converted to char: " << other << '\n';
}
