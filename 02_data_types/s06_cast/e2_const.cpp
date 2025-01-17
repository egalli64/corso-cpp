/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * const cast
 */
#include <iostream>

int main()
{
    const int x = 42;
    std::cout << "A constant int: " << x << '\n';

    const int *cpx = &x;

    // won't compile: expression must be a modifiable lvalue
    // *cpx += 1;

    int *px = const_cast<int *>(cpx);
    // !!! DANGEROUS: UNDEFINED BEHAVIOR !!!
    *px += 1;

    std::cout << "A constant int: " << x << '\n';
}
