/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Variable declaration, initialization, definition, assignment
 */
#include <iostream>

// if the context is limited, using namespace simplify the code
// using namespace std;

int main()
{
    // a is declared as int, but not initialized
    int a;
    // GCC: when compiled with -Wall flag -> warning: uninitialized
    // MSVC: warnings C6001 and C4700 (/sdl for error)
    // std::cout << "!!! BAD IDEA !!! " << a << '\n';

    a = 5; // a is initialized to 5
    std::cout << a << '\n';

    // variable definition preferred to split declaration and initialization
    int b = 7;
    std::cout << b << '\n';

    // assignment, changing value in a variable
    b = 42;
    std::cout << b << '\n';
}
