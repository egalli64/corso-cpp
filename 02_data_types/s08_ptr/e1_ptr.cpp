/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * pointer
 */

// MSVC define required for non-standard math constants as PI and E
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

int main()
{
    std::cout << "char* " << sizeof(char *) << '\n';
    std::cout << "double* " << sizeof(double *) << '\n';
    std::cout << '\n';

    // a char and a pointer to char
    char c = 'x';
    char *pc = &c;

    std::cout << "A char variable: " << c << ", accessed by pointer: " << *pc << '\n'
              << "The value in the pointer variable: " << static_cast<void *>(pc) << '\n';

    *pc = 'z';
    std::cout << "Value changed accessing the variable by pointer: " << c << "\n\n";

    // a double and a pointer to double
    double d = M_PI;
    double *pd = &d;

    std::cout << "A double variable: " << d << ", accessed by pointer: " << *pd << '\n'
              << "The value in the pointer variable: " << static_cast<void *>(pd) << '\n';

    *pd = M_E;
    std::cout << "Value changed accessing the variable by pointer: " << d << '\n';
}
