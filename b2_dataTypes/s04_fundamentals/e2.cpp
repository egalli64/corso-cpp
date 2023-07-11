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

    // implicit cast to boolean
    bool b_narrowed = 42;
    std::cout << "Boolean in C++ is actually a very small integer: " << b_false << ", ";
    std::cout << b_true << ", " << b_narrowed << '\n';

    char c = 'x';
    std::cout << "A character: " << c << '\n';

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

    int i_widened = c;
    std::cout << "A char implicitly converted to int: " << i_widened << '\n';

    char other = i_widened;
    std::cout << "A int implicitly converted to char: " << other << '\n';
}
