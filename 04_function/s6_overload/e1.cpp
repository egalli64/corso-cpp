/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * overload - same algorithm, different functions for different parameter types
 */
#include <iostream>

namespace
{
/**
 * @brief exchange the values in the parameters
 *
 * @param left a parameter
 * @param right another parameter
 */
void swap(int &left, int &right)
{
    std::cout << "swapping integers\n";
    int temp = left;
    left = right;
    right = temp;
}

/**
 * @brief exchange the values in the parameters
 *
 * @param left a parameter
 * @param right another parameter
 */
void swap(double &left, double &right)
{
    std::cout << "swapping doubles\n";
    double temp = left;
    left = right;
    right = temp;
}
} // namespace

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "a is " << a << " b is " << b << '\n';
    swap(a, b);
    std::cout << "a is " << a << " b is " << b << '\n';
    std::cout << "---\n";

    double d = 42.82;
    double e = 18.09;

    std::cout << "d is " << d << " e is " << e << '\n';
    swap(d, e);
    std::cout << "d is " << d << " e is " << e << '\n';
}
