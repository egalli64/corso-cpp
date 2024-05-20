/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: comparison
 */
#include <iostream>

int main()
{
    std::cout << "Comparison operators\n\n";

    int x = 42;
    int y = 18;

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';

    std::cout << "x == y is " << (x == y) << '\n';
    std::cout << "x != y is " << (x != y) << '\n';
    std::cout << "x < y is " << (x < y) << '\n';
    std::cout << "x <= y is " << (x <= y) << '\n';
    std::cout << "x > y is " << (x > y) << '\n';
    std::cout << "x >= y is " << (x >= y) << '\n';
}
