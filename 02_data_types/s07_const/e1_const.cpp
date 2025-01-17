/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * constexpr vs const
 */
#include <iostream>

constexpr int value()
{
    return 42;
}

const int value2()
{
    return 42;
}

int main()
{
    // evaluated at compile time
    constexpr int x = value();

    // won't compile: cannot call non-constexpr function
    // constexpr int x2 = value2();

    // won't compile: expression must be a modifiable lvalue
    // x += 1;

    // evaluated at runtime
    const int y = value();
    const int y2 = value2();

    // won't compile: expression must be a modifiable lvalue
    // y += 1;
    // y2 += 1;

    std::cout << "Using constants: " << x + y + y2 << '\n';
}
