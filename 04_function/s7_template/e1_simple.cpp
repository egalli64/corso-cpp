/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template
 */
#include <iostream>
#include <string>

namespace
{
/**
 * @brief a simple printing template function
 * 
 * @param x the T value to be printed
 */
template <typename T> void print(const T &x)
{
    std::cout << "The value is " << x << '\n';
}
} // namespace

int main()
{
    int a = 42;
    print(a);

    double d = 42.118;
    print(d);

    std::string s = "hello";
    print(s);
}
