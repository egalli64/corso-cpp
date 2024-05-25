/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types
 */
#include <iostream>

int main()
{
    bool b_false = false;
    bool b_true = true;

    // implicit cast between integer and boolean
    std::cout << "Booleans in C++ are actually very small integers: ";
    std::cout << b_false << ", " << b_true << '\n';

    bool b_narrowed = 42;
    std::cout << "Implicit cast of an int to bool: " << b_narrowed << '\n';

    b_narrowed = true + true;
    std::cout << "Implicit cast of booleans to int (and back to bool): ";
    std::cout << (true + true) << ", " << b_narrowed << '\n';

    // optional digit separator C++14
    int i = 49'385;
    std::cout << "An int: " << i << '\n';

    double d = 3.14159'26535;
    std::cout << "A double: " << d << '\n';

    //  Hexadecimal notation
    signed short int ssi = 0xFFFF;
    unsigned short int usi = 0xFFFF;
    std::cout << "A signed short integer: " << ssi << " and an unsigned short int: " << usi << '\n';

    std::string s = "Hello";
    std::cout << "A string: " << s << '\n';

    // characters are actually integers, too
    char c = 'x';
    std::cout << "A character: " << c << '\n';

    int i_widened = c;
    std::cout << "A char implicitly converted to int: " << i_widened << '\n';

    char other = i_widened;
    std::cout << "A int implicitly converted to char: " << other << '\n';
}
