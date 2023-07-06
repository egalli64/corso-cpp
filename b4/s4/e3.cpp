/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by reference
 */
#include <iostream>
using namespace std;

void swap(int &left, int &right)
{
    cout << "Called by reference: left is " << left << " and right is " << right << '\n';

    int temp = left;
    left = right;
    right = temp;
    cout << "Called by reference: left is " << left << " and right is " << right << '\n';
}

int main()
{
    int a = 42;
    int b = 18;

    cout << "Caller by reference: a is " << a << " and b is " << b << '\n';

    swap(a, b);
    cout << "Caller by reference: a is " << a << " and b is " << b << '\n';
}
