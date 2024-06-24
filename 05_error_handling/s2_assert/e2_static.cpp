/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * C++ static assert
 */
#include <iostream>

// evaluated at compile time
// static_assert(sizeof(int) == 8, "int should be 8 bytes");

int main()
{
    // if sizeof int is 4, i is more or less quietly assigned -1'486'618'624
    int i = 1'000'000'000'000'000'000;
    std::cout << "i = " << i << '\n';
}
