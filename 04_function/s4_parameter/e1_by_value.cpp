/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by value
 */
#include <iostream>

namespace
{
/**
 * @brief if the parameters are passed by values, no effect in their changes is seen in the caller
 *
 * @param left a parameter
 * @param right another parameter
 */
void wont_swap(int left, int right)
{
    std::cout << "Called by value: left is " << left << " and right is " << right << '\n';

    int temp = left;
    left = right;
    right = temp;

    std::cout << "Called by value: left is " << left << " and right is " << right << '\n';
}
} // namespace

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "Caller by value: a is " << a << " and b is " << b << '\n';

    wont_swap(a, b);
    std::cout << "Caller by value: a is " << a << " and b is " << b << '\n';
}
