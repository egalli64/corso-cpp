/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * for
 */
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << argv[0] << " has " << argc - 1 << " parameters\n";
    for (int i = 1; i < argc; ++i)
    {
        std::cout << i << ") " << argv[i] << '\n';
    }
}
