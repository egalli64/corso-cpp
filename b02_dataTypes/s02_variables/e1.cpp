/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Variable declaration, initialization, definition, assignment
 */
#include <iostream>

// if the context is limited, to avoid repeating "std::" is possible to use that namespace
// using namespace std;

int main()
{
    // a is declared as int, but not initialized
    int a;
    // when compiled with -Wall flag -> warning: uninitialized
    std::cout << "!!! BAD IDEA !!! " << a << '\n';

    a = 5; // a is initialized to 5
    std::cout << a << '\n';

    // variable definition preferred to split declaration and initialization
    int b = 7;
    std::cout << b << '\n';

    // assignment, changing value in a variable
    b = 42;
    std::cout << b << '\n';
}
