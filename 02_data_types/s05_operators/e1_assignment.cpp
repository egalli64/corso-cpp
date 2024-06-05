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

    // uniform initialization leads to warning/error
    // g++ 12 gives an error only when compiling with with -pedantic-errors
    // int b{value()};
    // int c{42.7};

    std::cout << "a is " << a << '\n';
    // std::cout << "b is " << b << '\n';
    // std::cout << "c is " << c << '\n';
}
