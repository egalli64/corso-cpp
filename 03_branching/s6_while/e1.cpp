/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * while
 */
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << argv[0] << " has " << argc - 1 << " parameters" << '\n';
    int i = 1;
    while (i < argc)
    {
        std::cout << i << ") " << argv[i] << '\n';
        i += 1;
    }
}
