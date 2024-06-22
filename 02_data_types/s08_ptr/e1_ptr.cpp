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
    std::cout << "Size of char* is " << sizeof(char *) << '\n';
    std::cout << "Size of double* is " << sizeof(double *) << " (same)\n";
    std::cout << '\n';

    // a char and a pointer to char
    char c = 'x';
    char *pc = &c;

    std::cout << "The content of a char var: " << c << '\n';
    // notice that the char* has to be casted to void*, otherwise is see as c-string!
    std::cout << "The content of a char* var: " << static_cast<void *>(pc) << '\n';
    // UNSAFE! write whichever char from the first until a '\0' is found
    // std::cout << "The content of a char* var: " << pc << '\n';
    std::cout << "The content of a char* var dereferenced: " << *pc << '\n';
    *pc = 'z';
    std::cout << "Both the char and char* variables refer to the same cell in memory: " << c << ' ' << *pc << "\n\n";

    // a double and a pointer to double
    double d = M_PI;
    double *pd = &d;

    std::cout << "The content of a double var: " << d << '\n';
    std::cout << "The content of a double* var: " << static_cast<void *>(pd) << '\n';
    std::cout << "The content of a double* var dereferenced: " << *pd << '\n';
    *pd = M_E;
    std::cout << "Both the double and double* variables refer to the same cell in memory: " << d << ' ' << *pd << '\n';
}
