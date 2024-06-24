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

/**
 * @brief when efficiency is required but not mutability, prefer using const ref
 *
 * @param lcm a reference to an object assumed to be costly to be created
 */
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
