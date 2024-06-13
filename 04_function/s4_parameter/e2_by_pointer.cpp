/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by pointer
 */
#include <iostream>

namespace
{
void swap(int *pLeft, int *pRight)
{
    // ensure the pointer is dereferencable
    if (pLeft == nullptr || pRight == nullptr)
    {
        std::cout << "Can't swap from " << pLeft << " to " << pRight << '\n';
    }
    else
    {
        std::cout << "Called by pointer: left is " << *pLeft << " and right is " << *pRight << '\n';

        int temp = *pLeft;
        *pLeft = *pRight;
        *pRight = temp;

        std::cout << "Called by pointer: left is " << *pLeft << " and right is " << *pRight << '\n';
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
