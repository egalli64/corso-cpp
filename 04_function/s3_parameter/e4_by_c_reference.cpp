/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by reference
 */
#include <iostream>

namespace
{
struct LargeClassMock
{
    int x;
};

void hello(const LargeClassMock &lcm)
{
    std::cout << "Hello " << lcm.x << '\n';

    // won't compile
    // lcm.x += 1;
}
} // namespace

int main()
{
    LargeClassMock lcm{42};
    hello(lcm);
}
