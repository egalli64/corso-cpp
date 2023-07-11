/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * pointer
 */
#include <iostream>
#include <cmath>

int main()
{
    std::cout << "char* " << sizeof(char *) << '\n';
    std::cout << "double* " << sizeof(double *) << '\n';
    std::cout << '\n';

    // a char and a pointer to char
    char c = 'x';
    char *pc = &c;

    std::cout << c << ' ' << *pc << ' ' << static_cast<void *>(pc) << '\n';
    *pc = 'z';
    std::cout << c << ' ' << *pc << '\n';

    // a double and a pointer to double
    double d = M_PI;
    double *pd = &d;

    std::cout << d << ' ' << *pd << ' ' << pd << '\n';
    *pd = M_E;
    std::cout << d << ' ' << *pd << '\n';
}
