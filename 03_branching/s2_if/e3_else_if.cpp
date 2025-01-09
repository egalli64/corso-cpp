/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Branching: if - else if - ... - else
 */
#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "The caller ";
    if (argc == 1)
    {
        std::cout << "didn't pass any argument\n";
    }
    else if (argc == 2)
    {
        std::cout << "passed a argument: " << argv[1] << '\n';
        if (isdigit(argv[1][0]))
        {
            std::cout << "First char is a digit!" << '\n';
        }
    }
    else if (argc % 2)
    {
        std::cout << "passed an even number of arguments\n";
    }
    else
    {
        std::cout << "passed an odd number of arguments\n";
    }
}
