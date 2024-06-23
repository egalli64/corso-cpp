/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by pointer
 */
#include <iostream>

namespace
{
/**
 * @brief Passing arguments by pointer is inherently dangerous
 *
 * @param p_left a parameter
 * @param p_right another parameter
 */
void swap(int *p_left, int *p_right)
{
    // ensure the pointer is dereferencable
    if (p_left == nullptr || p_right == nullptr)
    {
        std::cout << "Can't swap from " << p_left << " to " << p_right << '\n';
    }
    else
    {
        std::cout << "Called by pointer: left is " << *p_left << " and right is " << *p_right << '\n';

        int temp = *p_left;
        *p_left = *p_right;
        *p_right = temp;

        std::cout << "Called by pointer: left is " << *p_left << " and right is " << *p_right << '\n';
    }
}
} // namespace

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "Caller by pointer: a is " << a << " and b is " << b << '\n';

    swap(&a, &b);
    std::cout << "Caller by pointer: a is " << a << " and b is " << b << '\n';

    swap(&a, nullptr);
}
