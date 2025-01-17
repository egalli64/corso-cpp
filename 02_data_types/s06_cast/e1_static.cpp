/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * static cast
 */
#include <iostream>
#include <string>

double f()
{
    double result = 4.2;

    std::cout << "The value generated in f() is " << result << '\n';

    return result;
}

int main()
{
    int a = f();
    std::cout << "An implicit narrowing could be difficult to spot: " << a << '\n';

    // For GCC it is just a warning, or: g++ -pedantic-errors e1_static.cpp
    // int b{f()};
    // std::cout << "The universal initializer makes the narrowing visible: " << b << '\n';

    int c{static_cast<int>(f())};
    std::cout << "Static cast makes clear we know about the narrowing: " << c << '\n';

    // automatic type deduction (here: double)
    auto d = f();

    std::cout << "Using auto, d is " << d << " and it is type, deduced by the compiler, is sized " << sizeof(d) << '\n';
}
