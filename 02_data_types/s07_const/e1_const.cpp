/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * constexpr vs const
 */
#include <iostream>

namespace
{
constexpr int value()
{
    return 42;
}

const int value2()
{
    return 42;
}

} // namespace

int main()
{
    // evaluated at compile time
    constexpr int x = value();
    // cannot call non-constexpr function
    // constexpr int x2 = value2();

    // error!
    // x += 1;

    // won't change
    const int y = value();
    const int y2 = value2();

    // y += 1; // error!

    std::cout << "Using constants: " << x + y + y2 << '\n';
}
