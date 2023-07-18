/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * C++ static assert
 */
#include <iostream>

// static_assert(sizeof(int) == 8, "int should be 8 bytes");

int main()
{
    int i = 1'000'000'000'000'000'000;
    std::cout << "i = " << i << '\n';
}
