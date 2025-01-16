/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Alias types
 */
#include <cstdint>
#include <iostream>

int main()
{
    std::int8_t x = 42;
    std::cout << "sizeof int8_t is " << sizeof(std::int8_t) << '\n';
    std::cout << "sizeof an int8_t variable is " << sizeof(x) << '\n';
}
