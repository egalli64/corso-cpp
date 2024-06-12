/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template
 */
#include <iostream>
#include <string>

namespace my
{
template <typename T> void swap(T &left, T &right)
{
    T temp = left;
    left = right;
    right = temp;
}
} // namespace my

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "a is " << a << " b is " << b << '\n';
    my::swap(a, b);
    std::cout << "a is " << a << " b is " << b << '\n';

    std::string s = "hello";
    std::string t = "ciao";

    std::cout << "s is " << s << " t is " << t << '\n';
    my::swap(s, t);
    std::cout << "s is " << s << " t is " << t << '\n';
}
