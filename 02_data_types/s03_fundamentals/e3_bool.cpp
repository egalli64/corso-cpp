/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Fundamental types - bool
 */
#include <iostream>

int main()
{
    // For C compability, boolean is an integral type (0/1 values)
    bool b_false = false;
    bool b_true = true;

    // implicit cast between integer and boolean
    std::cout << "Booleans in C++ are actually very small integers: ";
    std::cout << b_false << ", " << b_true << '\n';

    int an_int = 42;
    bool b_narrowed = an_int;
    std::cout << "Implicit cast of an int (" << an_int << ") to bool: " << b_narrowed << '\n';

    // the operator + cause widening to int
    std::cout << "Implicit cast of booleans to int: true + true makes " << true + true << "!\n";
    // the operator = cause narrowing to bool
    b_narrowed = true + true;
    std::cout << "Implicit cast of int to bool: " << b_narrowed << '\n';
}
