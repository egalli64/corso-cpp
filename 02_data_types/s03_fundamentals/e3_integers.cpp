/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - integers
 */
#include <iostream>

int main()
{
    // optional digit separator C++14
    int i = 49'385'949;
    std::cout << "An int: " << i << '\n';

    //  Hexadecimal notation
    signed short int ssi = 0xFFFF; // all bits set to 1 -> -1
    unsigned short int usi = 0xFFFF; // all bits set to 1 -> 65535
    std::cout << "A signed short integer: " << ssi << " and an unsigned short int: " << usi << '\n';
}
