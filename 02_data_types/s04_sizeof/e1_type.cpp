/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Size of fundamental types
 */
#include <iostream>

int main()
{
    std::cout << "bool: " << sizeof(bool) << '\n';
    std::cout << "char: " << sizeof(char) << '\n';
    std::cout << "short: " << sizeof(short) << '\n';
    std::cout << "int: " << sizeof(int) << '\n';
    std::cout << "int64_t: " << sizeof(int64_t) << '\n';
    std::cout << "long: " << sizeof(long) << '\n';
    std::cout << "long long: " << sizeof(long long) << '\n';

    std::cout << '\n';

    std::cout << "float: " << sizeof(float) << '\n';
    std::cout << "double: " << sizeof(double) << '\n';
    std::cout << "long double: " << sizeof(long double) << '\n';
}
