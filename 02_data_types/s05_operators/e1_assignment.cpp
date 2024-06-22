/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Operators: assignment
 */
#include <iostream>

namespace
{
double value()
{
    return 42.7;
}
} // namespace

int main()
{
    // implicit narrowing, compiles fine
    int a = value();
    std::cout << "a is " << a << '\n';

    // uniform initialization leads to warning/error
    // g++ 12 gives an error only when compiling with with -pedantic-errors
    // int b{value()};
    // std::cout << "b is " << b << '\n';
}
