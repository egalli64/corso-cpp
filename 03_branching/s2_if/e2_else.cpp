/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Branching: if - else
 */
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "The caller ";
    if (argc == 1)
    {
        std::cout << "didn't pass any argument\n";
    }
    else
    {
        std::cout << "passed at least a argument\n";
    }
    std::cout << "Bye\n";
}
