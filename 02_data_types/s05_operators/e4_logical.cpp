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

    bool is_x_even = x % 2 == 0;
    bool is_y_even = y % 2 == 0;
    std::cout << "Both x and y are even: " << (is_x_even && is_y_even) << '\n';
    std::cout << "x or y is even (or both): " << (is_x_even || is_y_even) << '\n';
    std::cout << "y is not even: " << !is_y_even << '\n';

    bool x_as_boolean = x;
    std::cout << "With assignment, numbers are silently narrowed to boolean: " << x_as_boolean << '\n';

    // GNU just warns about narrowing, to get an error: g++ -pedantic-errors e4_logical.cpp
    // bool by{y};
    // std::cout << "Uniform initializer helps identifying a possible issue: " << by << '\n';

    std::cout << std::noboolalpha;

    std::cout << "true is actually " << true << '\n';
    std::cout << "false is actually " << false << '\n';
}
