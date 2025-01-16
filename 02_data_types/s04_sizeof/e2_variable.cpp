/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * sizeof() on variables
 */
#include <iostream>

int main()
{
    int a = 42;
    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(a) << "\n\n";

    double d = 4.2;
    std::cout << sizeof(double) << '\n';
    std::cout << sizeof(d) << '\n';
}
