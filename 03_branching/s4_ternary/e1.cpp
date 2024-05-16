/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Ternary operator ?:
 */
#include <iostream>

int main(int argc, char **argv)
{
    const char *name = argc > 1 ? argv[1] : "Unknown";
    std::cout << "Hello " << name << '!' << '\n';
}
