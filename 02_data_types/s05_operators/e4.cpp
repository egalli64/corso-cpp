/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: assignment
 */
#include <iostream>

int main()
{
    int x{42};
    int y{18};

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';

    std::cout << "\nAssignment operators\n\n";
    std::cout << "after x += y the value in x is " << (x += y) << '\n';
    std::cout << "after x -= y the value in x is " << (x -= y) << '\n';
    std::cout << "after ++x the value in x is " << ++x << '\n';
    std::cout << "after --x the value in x is " << --x << '\n';
}
