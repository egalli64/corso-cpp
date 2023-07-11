/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda capturing by value mutable
 */
#include <iostream>

int main()
{
    int a = 1;

    // by value mutable
    [a]() mutable
    {
        std::cout << "Captured increased to " << ++a << '\n';
    }();

    std::cout << "Original 'a' is still " << a << '\n';
}
