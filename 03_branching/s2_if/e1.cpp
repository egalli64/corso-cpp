/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * if
 */
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello!\n";
    if (argc == 1)
    {
        std::cout << "The caller didn't pass any argument\n";
    }
    std::cout << "Bye\n";
}
