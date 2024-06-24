/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template example - more meta parameters
 */
#include <iostream>

namespace
{
/**
 * @brief template function to get the max from the passed arguments
 * @param a the first parameter
 * @param b the second parameter
 * @return the larger one
 */
template <typename T> T max(const T &a, const T &b)
{
    return a > b ? a : b;
}

// More complicated, how T and U interact?
// template <typename T, typename U> T max(const T &a, const U &b)
// {
//     return a > b ? a : b;
// }
} // namespace

int main()
{
    int a = max(5, 10);
    std::cout << "Max is: " << a << '\n';

    // won't compile, no implicit conversion from char to int
    // int a1 = max(5, '1');
    // std::cout << "Max is: " << a1 << '\n';

    // when required, use an explicit conversion
    int a2 = max(5, static_cast<int>('1'));
    std::cout << "Max is: " << a2 << '\n';

    float b = max(3.14f, 2.71f);
    std::cout << "Max is: " << b << '\n';

    char c = max('a', 'z');
    std::cout << "Max is: " << c << '\n';
}
