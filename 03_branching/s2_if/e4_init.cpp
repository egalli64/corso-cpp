/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Branching: if with initializer (C++17)
 */
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello!\n";
    if (bool empty{argc == 1}; empty)
    {
        std::cout << "Is the argument array empty? " << std::boolalpha << empty << '\n';
    }

    // won't compile: identifier "empty" is undefined
    // std::cout << empty <<'\n';

    std::cout << "Bye\n";
}
