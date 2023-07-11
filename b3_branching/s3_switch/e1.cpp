/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * switch
 */
#include <iostream>

int main(int argc, char **argv)
{
    switch (argc)
    {
    case 1:
        std::cout << "The caller didn't pass any parameter\n";
        break;
    case 2:
        std::cout << "The first parameter is " << argv[1] << '\n';
        break;
    default:
        std::cout << "The last parameter is " << argv[argc - 1] << '\n';
        break;
    }
}
