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
    std::cout << "!!! BAD IDEA !!! Accessing an uninitialized variable: " << a << '\n';

    // a is initialized to 5
    a = 5;

    // using the variable a in an instruction (to print its value)
    std::cout << "Variable initialized to " << a << '\n';

    // variable definition preferred to split declaration and initialization
    int b = 7;
    std::cout << "Variable defined as " << b << '\n';

    // the compiler deduces the variable type using the value on the right side
    auto c = 21;
    std::cout << "Variable type deduced by compiler by its initializing value " << c << '\n';

    // assignment, changing value in a variable
    c = 42;
    std::cout << "After assignment: " << c << '\n';
}
