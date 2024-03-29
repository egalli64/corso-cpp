/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda capturing a variable by reference - a mistake!
 */
#include <functional>
#include <iostream>

namespace
{
std::function<void()> veryBad()
{
    int x = 42;

    auto result = [&x]() { std::cout << "Captured is " << x << '\n'; };

    std::cout << "Inside function is alright. ";
    result();

    return result;
}
} // namespace

int main()
{
    auto lambda = veryBad();

    std::cout << "Undefined behavior, reference to a variable out of scope! ";
    lambda();
}
