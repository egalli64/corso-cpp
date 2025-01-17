/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: logical
 */
#include <iostream>

int main()
{
    int x = 42;
    int y = 23;

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';

    std::cout << "\nLogical operators\n\n";

    std::cout << std::boolalpha;

    std::cout << "Both x and y are even: " << (x % 2 && y % 2) << '\n';
    std::cout << "x or y is even (or both): " << (x % 2 || y % 2) << '\n';
    std::cout << "y is not even: " << !(x % 2) << '\n';

    bool bx = x;
    std::cout << "With assignment, numbers are silently narrowed to boolean: " << bx << '\n';

    // GNU just warns, to get an error: g++ -pedantic-errors e4_logical.cpp
    // bool by{y};
    // std::cout << "Uniform initializer helps identifying a possible issue: " << by << '\n';

    std::cout << std::noboolalpha;

    std::cout << "true is actually " << true << '\n';
    std::cout << "false is actually " << false << '\n';
}
