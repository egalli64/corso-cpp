/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * throw exception
 */
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        // Can't do anything sensible without any argument
        throw 42;
    }

    std::cout << "The first argument is: " << argv[1] << '\n';
}
