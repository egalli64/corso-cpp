/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - bool
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
}
