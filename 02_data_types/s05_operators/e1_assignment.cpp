/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: assignment
 */
#include <iostream>

double value()
{
    return 42.7;
}

int main()
{
    // implicit narrowing (could be a mistake!)
    int x = value();
    // uniform initialization here leads to error: explicit narrowing required (safer)
    int a{value()};

    int y = 18;

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';
}
