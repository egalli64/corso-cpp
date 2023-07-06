/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by pointer
 */
#include <iostream>
using namespace std;

void swap(int *pLeft, int *pRight)
{
    cout << "Called by pointer: left is " << *pLeft << " and right is " << *pRight << '\n';

    int temp = *pLeft;
    *pLeft = *pRight;
    *pRight = temp;

    cout << "Called by pointer: left is " << *pLeft << " and right is " << *pRight << '\n';
}

int main()
{
    int a = 42;
    int b = 18;

    cout << "Caller by pointer: a is " << a << " and b is " << b << '\n';

    swap(&a, &b);
    cout << "Caller by pointer: a is " << a << " and b is " << b << '\n';
}
