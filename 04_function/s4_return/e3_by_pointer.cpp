/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * return by pointer
 */
#include <iostream>

/**
 * @brief Defining a function returning an int by pointer
 */
int *max(int *pLeft, int *pRight)
{
    return *pLeft > *pRight ? pLeft : pRight;
}

int main()
{
    int left = 42;
    int right = 12;
    int* px = max(&left, &right);

    std::cout << "The largest value between " << left << " and " << right << " is " << *px << '\n';
}
