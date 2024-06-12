/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by value
 */
#include <iostream>

void wontSwap(int left, int right)
{
    std::cout << "Called by value: left is " << left << " and right is " << right << '\n';

    int temp = left;
    left = right;
    right = temp;

    std::cout << "Called by value: left is " << left << " and right is " << right << '\n';
}

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "Caller by value: a is " << a << " and b is " << b << '\n';

    wontSwap(a, b);
    std::cout << "Caller by value: a is " << a << " and b is " << b << '\n';
}
