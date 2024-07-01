/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda capturing a variable by reference - a mistake!
 */
#include <functional>
#include <iostream>

namespace
{
/**
 * @brief generate a lambda that captures a local variable by ref!
 * @bug when the lambda is invoked out of this scope there is an undefined behavior
 * @return the lambda as void function not expecting any argument - as alternative, "auto" could be used
 */
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
