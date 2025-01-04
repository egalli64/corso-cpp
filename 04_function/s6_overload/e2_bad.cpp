/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * overload - avoid ambiguity
 */
#include <iostream>

void f(int x, double y)
{
    std::cout << "Do something with " << x << " (int) and " << y << " (double)\n";
}

void f(double a, int b)
{
    std::cout << "Do something with " << a << " (double) and " << b << " (int)\n";
}

int main()
{
    // won't compile: more than one instance of overloaded function "f" matches the argument list
    // f(42, 12);
    // f(42.0, 12.0);

    f(42.0, 12);
    f(42, 12.0);
}
