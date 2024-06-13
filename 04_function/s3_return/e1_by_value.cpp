/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by value
 */
#include <iostream>

namespace
{
int answer()
{
    return 42;
}
} // namespace

int main()
{
    int x = answer();
    std::cout << "The answer is " << x << '\n';
}
