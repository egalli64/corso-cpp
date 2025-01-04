/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * parameter - by reference
 */
#include <iostream>

/**
 * @brief a function getting arguments by reference
 */
void swap(int &left, int &right)
{
    std::cout << "Called by reference: left is " << left << " and right is " << right << '\n';

    int temp = left;
    left = right;
    right = temp;
    std::cout << "Called by reference: left is " << left << " and right is " << right << '\n';
}

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "Caller by reference: a is " << a << " and b is " << b << '\n';

    swap(a, b);
    std::cout << "Caller by reference: a is " << a << " and b is " << b << '\n';
}
