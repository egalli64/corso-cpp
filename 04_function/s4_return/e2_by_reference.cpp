/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * return by reference
 */
#include <iostream>

/**
 * @brief Defining a function returning an int by reference
 */
int &max(int &left, int &right)
{
    return left > right ? left : right;
}

int main()
{
    int left = 42;
    int right = 12;
    int &x = max(left, right);

    std::cout << "The largest value between " << left << " and " << right << " is " << x << '\n';
}
