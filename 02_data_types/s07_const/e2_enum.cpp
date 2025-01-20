/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * "classic" enum
 */
#include <iostream>

// a simple enumeration
enum Greek
{
    ALPHA,
    BETA = 28
};

// unnamed enumeration
enum
{
    SOME_VALUE = 99
};

Greek f()
{
    return ALPHA;
}

int main()
{
    std::cout << "ALPHA is " << ALPHA << " and BETA is " << BETA << '\n';

    Greek x = f();

    // comparing values from different enum leads to a warning
    // code like this is error prone and difficult to mantain
    if (x == SOME_VALUE)
    {
        std::cout << "Unexpected\n";
    }

    // not even a warning when comparing an enum with a plain int!
    if (x == 42)
    {
        std::cout << "Unexpected\n";
    }
}
