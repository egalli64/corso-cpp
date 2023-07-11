/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * switch - fall through
 */
#include <iostream>

int main(int argc, char **argv)
{
    switch (argc)
    {
    default:
        std::cout << "The last parameter is " << argv[argc - 1] << '\n';
        // !!! FALL THROUGH - DO NOT BREAK HERE !!!
    case 2:
        std::cout << "The first parameter is " << argv[1] << '\n';
        // !!! FALL THROUGH - DO NOT BREAK HERE !!!
    case 1:
        std::cout << "The program has been invoked with name " << argv[0] << '\n';
        break;
    }
}
