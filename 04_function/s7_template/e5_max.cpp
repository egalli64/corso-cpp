/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template example - max
 */
#include <iostream>

/**
 * @brief a simple template function, both parameters should have the same type
 */
template <typename T> T max(const T &a, const T &b)
{
    return a > b ? a : b;
}

int main()
{
    std::cout << "Max is: " << max(5, 10) << '\n';

    // won't compile, no implicit conversion from char to int
    // std::cout << max(5, '1');

    // when required, use an explicit conversion
    std::cout << "Max is: " << max(5, static_cast<int>('1')) << '\n';

    std::cout << "Max is: " << max(3.14f, 2.71f) << '\n';
    std::cout << "Max is: " << max('a', 'z') << '\n';
}
