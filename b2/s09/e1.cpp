/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * reference
 */
#include <iostream>
using namespace std;

int main()
{
    int value = 84;
    int *ptr = &value;
    cout << "A single int variable, address and value: " << ptr << " -> " << *ptr << '\n';

    // a pointer could change its referred memory location
    int other = 27;
    ptr = &other;
    cout << "The int 'other', address and value: " << ptr << " -> " << *ptr << '\n';

    // a reference won't change its referred memory location
    int &ref = value;
    cout << "ref and value " << ref << ' ' << value << '\n';

    ref += 1;
    cout << "ref and value after increasing ref " << ref << ' ' << value << '\n';

    // this is _not_ a reassignment of reference, the _value_ in other is assigned to the variable reference by ref
    ref = other;
    other += 1;
    cout << "ref, value, and other: " << ref << ' ' << value << ' ' << other << '\n';
}
