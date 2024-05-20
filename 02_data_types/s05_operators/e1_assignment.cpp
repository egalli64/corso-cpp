/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: assignment, arithmetic, string concatenation
 */
#include <iostream>

int main()
{
    // implicit narrowing (could be a mistake!)
    int x = 42.7;
    // uniform initialization here leads to error: explicit narrowing required (safer)
    // int a {42.7};

    int y = 18;

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';
}
