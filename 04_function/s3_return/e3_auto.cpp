/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * auto return type
 */
#include <iostream>

namespace
{
auto answer()
{
    return 42;
}
} // namespace

int main()
{
    auto x = answer();
    std::cout << "The answer is " << x << '\n';
}
