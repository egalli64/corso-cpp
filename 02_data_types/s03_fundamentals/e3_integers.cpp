/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - integers
 */
#include <iostream>

int main()
{
    // optional digit separator C++14
    int i = 49'385;
    std::cout << "An int: " << i << '\n';

    //  Hexadecimal notation
    signed short int ssi = 0xFFFF;
    unsigned short int usi = 0xFFFF;
    std::cout << "A signed short integer: " << ssi << " and an unsigned short int: " << usi << '\n';
}
