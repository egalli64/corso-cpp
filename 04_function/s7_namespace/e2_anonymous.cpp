/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * an anonymous namespace
 */
#include <iostream>

namespace
{
int counter = 42;

void hello()
{
    std::cout << "Hello\n";
}
} // namespace

// using namespace my;

int main()
{
    hello();

    std::cout << "The counter value is " << counter << '\n';
}
