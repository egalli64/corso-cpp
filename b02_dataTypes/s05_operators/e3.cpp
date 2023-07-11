/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: bitwise
 */
#include <bitset>
#include <iostream>

int main()
{
    unsigned int x{42};
    unsigned int y{18};

    std::cout << "\nBitwise operators\n\n";
    std::cout << "x is " << x << " (" << std::bitset<8>(x) << ')' << '\n';
    std::cout << "y is " << y << " (" << std::bitset<8>(y) << ')' << '\n';
    std::cout << '\n';

    std::cout << "x & y is " << std::bitset<8>(x & y) << '\n';
    std::cout << "x | y is " << std::bitset<8>(x | y) << '\n';
    std::cout << "x ^ y is " << std::bitset<8>(x ^ y) << '\n';
    // '~' topleft on US keyboard, or alt-126, or altGr-ì
    std::cout << "~x is " << std::bitset<8>(~x) << '\n';
}
