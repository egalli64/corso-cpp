/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: comparison, logical
 */
#include <iostream>

int main()
{
    int x{42};
    int y{18};

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';

    std::cout << "\nComparison operators\n\n";

    std::cout << "x == y is " << (x == y) << '\n';
    std::cout << "x != y is " << (x != y) << '\n';
    std::cout << "x < y is " << (x < y) << '\n';
    std::cout << "x <= y is " << (x <= y) << '\n';
    std::cout << "x > y is " << (x > y) << '\n';
    std::cout << "x >= y is " << (x >= y) << '\n';

    std::cout << "\nLogical operators\n\n";
    std::cout << "x && y is " << (x && y) << '\n';
    std::cout << "x || y is " << (x || y) << '\n';
    std::cout << "!x is " << !x << '\n';
}
