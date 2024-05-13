/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: assignment, arithmetic, string concatenation
 */
#include <iostream>

int main()
{
    int x = 42;
    int y{18};

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';

    std::cout << "\nArithmetic operators\n\n";

    std::cout << "x + y is " << x + y << '\n';
    std::cout << "+x is " << +x << '\n';
    std::cout << "x - y is " << x - y << '\n';
    std::cout << "-x is " << -x << '\n';
    std::cout << "x * y is " << x * y << '\n';
    std::cout << "x / y is " << x / y << '\n';
    std::cout << "x % y is " << x % y << '\n';

    std::cout << "\nString concatenation\n\n";
    std::string s{"Hello"};
    std::string t{"World!"};
    std::cout << s + ", " + t << '\n';
}
