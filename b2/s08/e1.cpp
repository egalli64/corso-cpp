/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * pointer
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "char* " << sizeof(char *) << '\n';
    cout << "double* " << sizeof(double *) << '\n';
    cout << '\n';

    // a char and a pointer to char
    char c = 'x';
    char *pc = &c;

    cout << c << ' ' << *pc << ' ' << static_cast<void *>(pc) << '\n';
    *pc = 'z';
    cout << c << ' ' << *pc << '\n';

    // a double and a pointer to double
    double d = M_PI;
    double *pd = &d;

    cout << d << ' ' << *pd << ' ' << pd << '\n';
    *pd = M_E;
    cout << d << ' ' << *pd << '\n';
}
